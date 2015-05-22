#include "epsifilecompressor.h"
#include <QString>
#include "filepool.h"
#include "zippedbufferpool.h"
#include "zipper.h"
#include "writer.h"
#include <memory>
#include <list>

using namespace std;

EpsiFileCompressor::EpsiFileCompressor(const int &nbThreads)
{
}

EpsiFileCompressor::compress(const QString &folder, const QString ecfFileName)
{
    FilePool filePool(folder);
    ZippedBufferPool zbPool;
    typedef unique_ptr<Zipper> ZipperPtr;
    list<ZipperPtr> zippers;
    Writer writer;

    for(int i = 0;i < nbThreads;++i)
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

EpsiFileCompressor::uncompress(const QString &ecfFileName, const QString &folder)
{

}
