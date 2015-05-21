#include "filepool.h"
#include "zippedbufferpool.h"
#include "zipper.h"
#include <QCoreApplication>
#include <list>
#include <QThread>
#include <QElapsedTimer>
#include <iostream>
#include <memory>
using namespace std;

void test()
{
    FilePool filePool("D:\\Theo\\Cours\\NoSQL\\");
    ZippedBufferPool zbPool;
    typedef unique_ptr<Zipper> ZipperPtr;
    list<ZipperPtr> zippers;
    for(int i = 0;i < 4;++i) {
       auto ptr = new Zipper(filePool, zbPool);
       zippers.push_back(ZipperPtr(ptr));
       zippers.back()->start();
   }
    while(!zippers.empty())
    {
        zippers.front()->wait();
        zippers.pop_front();
    }
    zbPool.setDone();
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    test();

    return 0;
   // return a.exec();
}
