#include "writer.h"
#include <QFile>

Writer::Writer(ZippedBufferPool &zippedBufferPool, const QString &fileName):
    zpPool_(zippedBufferPool), fileToWrite_(fileName)
{       
}

void Writer::run()
{
    fileToWrite_.open(QFile::ReadWrite);
    QDataStream stream_(&fileToWrite_);
    QPair<bool,ZippedBuffer> buffer;
    buffer = zpPool_.tryGet();
    while(buffer.first == true)
    {
        buffer.second.write(stream_);

        buffer = zpPool_.tryGet();
    }
    write();
}

void Writer::write()
{
    fileToWrite_.close();
}
