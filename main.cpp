#include <QCoreApplication>
#include <QString>

#include "epsifilecompressor.h"
using namespace std;


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    EpsiFileCompressor efc(4);
    //QString folder = "D:\\Theo\\CV";
    //QString folder = "D:\\Theo\\BackUps\\BackUpOldSys\\C#";
    QString folder = "D:\\Theo\\Cours";
    QString file = "D:\\Theo\\cours.ecf";
    efc.compress(folder,file);

    folder = "D:\\Theo\\TestCompress\\Cours";
    efc.uncompress(file,folder);

    return 0;
   // return a.exec();
}
