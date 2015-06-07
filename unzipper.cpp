#include "unzipper.h"
#include <QDir>
#include <QDebug>

Unzipper::Unzipper(ZippedBufferPool &zbPool, const QString &folder):
    zbPool_(zbPool),extractFolder_(folder)
{
}


void Unzipper::run()
{
    QPair<bool,ZippedBuffer> pair;
    pair = zbPool_.tryGet();
    // Tant qu'il y a des fichiers dans le pool
    while(pair.first == true){
        // compresse le fichier
        uncompressFile(pair.second);
        // essaye de prendre un autre fichier
        // à traiter
        pair = zbPool_.tryGet();
    }
}

void Unzipper::uncompressFile(ZippedBuffer &zb)
{
    QString relativPath = zb.getRelativePath();
    QString absolutePath = getAbsolutePath(relativPath);
    //qDebug() << "path : " <<absolutePath;
    makePath(absolutePath);
    QByteArray uncompressedData = qUncompress(zb.getCompressedDatas());
    QFile file(absolutePath);
    if (file.open(QIODevice::ReadWrite))
    {
        file.write(uncompressedData);
        file.close();
    }
}


QString Unzipper::getAbsolutePath(const QString &file_name)
{
    return extractFolder_ + file_name;
}

void Unzipper::makePath(const QString &filename)
{
    QString folderPart = filename.left(filename.lastIndexOf('\\'));
    QDir dir(folderPart);
    if (!dir.exists())
    {
        dir.mkpath(".");
    }
}
