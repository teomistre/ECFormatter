#include "zipper.h"
#include <QFile>
#include <QDebug>

Zipper::Zipper(FilePool &filePool, ZippedBufferPool &zippedBufferPool):
    filePool_(filePool), zpPool_(zippedBufferPool)
{
}

void Zipper::run()
{
    QString filename;
    filename = filePool_.tryGetFile();    
    // Tant qu'il y a des fichiers dans le pool
    while(filename != "") {
        // compresse le fichier
        compressFile(filename);
        // essaye de prendre un autre fichier
        // à traiter
        filename = filePool_.tryGetFile();
    }    
}


void Zipper::compressFile(const QString &file_name)
{
    QFile file(file_name);   
    if (file.open(QFile::ReadOnly) == true)
    {        
        ZippedBuffer zippedBuffer;
        zippedBuffer.setRelativePath(getRelativePath(file_name));
        zippedBuffer.setCompressedData((qCompress(file.readAll())));
        zpPool_.put(zippedBuffer);
    }
}

QString Zipper::getRelativePath(const QString &file_name)
{
    QString result = file_name;
    result.replace('/','\\');
    result.replace(filePool_.getFolderPath(),"");
    //qDebug() << result;
    return result;
}
