#include <QCoreApplication>
#include <QString>

#include "epsifilecompressor.h"
using namespace std;


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    EpsiFileCompressor efc(2);
    QString folder = "D:\\Theo\\CV";
    QString file = "D:\\Theo\\cv.ecf";
    efc.compress(folder,file);

    return 0;
   // return a.exec();
}
