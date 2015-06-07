#include "epsifilecompressor.h"
#include <QString>
#include "filepool.h"
#include "zippedbufferpool.h"
#include "zipper.h"
#include "writer.h"
#include "unzipper.h"
#include <memory>
#include <list>
#include <QDebug>

using namespace std;

EpsiFileCompressor::EpsiFileCompressor(const int &nbThreads):
    nbThreads_(nbThreads)
{
}

void EpsiFileCompressor::compress(const QString &folder, const QString &ecfFileName)
{
    FilePool filePool(folder);
    qDebug() << folder;
    ZippedBufferPool zbPool;
    typedef unique_ptr<Zipper> ZipperPtr;
    list<ZipperPtr> zippers;
    Writer writer(zbPool,ecfFileName);

    for(int i = 0;i < nbThreads_;++i)
    {
       auto ptr = new Zipper(filePool, zbPool);
       zippers.push_back(ZipperPtr(ptr));
       zippers.back()->start();
    }
    writer.start();
    while(!zippers.empty())
    {
        zippers.front()->wait();
        zippers.pop_front();
    }
    zbPool.setDone();
    writer.wait();
}

void EpsiFileCompressor::uncompress(const QString &ecfFileName, const QString &folder)
{
       ZippedBufferPool zbPool;
       QFile file(ecfFileName);
       if (file.open(QFile::ReadOnly) == true)
       {
           QDataStream stream(&file);
           while(!stream.atEnd())
           {
               ZippedBuffer zb;
               zb.read(stream);
               zbPool.put(zb);
           }
           zbPool.setDone();
       }

       typedef unique_ptr<Unzipper> UnzipperPtr;
       list<UnzipperPtr> unzippers;

       for(int i = 0;i < nbThreads_;++i)
       {
          auto ptr = new Unzipper(zbPool, folder);
          unzippers.push_back(UnzipperPtr(ptr));
          unzippers.back()->start();
       }
       while (!unzippers.empty()) {
           unzippers.front()->wait();
           unzippers.pop_front();
       }


}
