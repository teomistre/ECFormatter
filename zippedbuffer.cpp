#include "zippedbuffer.h"
#include <QDataStream>

ZippedBuffer::ZippedBuffer(const QString &relativeFilePath, const QByteArray &compressedData):
    relativeFilePath_(relativeFilePath),compressedData_(compressedData)
{
}


ZippedBuffer::write(QDataStream &stream)
{
    while(stream.atEnd() == false)
    {

        stream.readRawData(_, QIODevice::ReadOnly);
    }

}
