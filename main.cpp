#include <QCoreApplication>
#include <QString>

#include "epsifilecompressor.h"
using namespace std;


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    EpsiFileCompressor efc(4);
    //QString folder = "D:\\Theo\\CV";
    QString folder = "D:\\Theo\\BackUps\\BackUpOldSys\\C#";
    QString file = "D:\\Theo\\c#.ecf";
    efc.compress(folder,file);

    return 0;
   // return a.exec();
}
