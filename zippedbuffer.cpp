#include "zippedbuffer.h"
#include <QDataStream>

ZippedBuffer::ZippedBuffer()
{
}

void ZippedBuffer::setRelativePath(const QString &relativePath)
{
    this->relativeFilePath_ = relativePath;
}

void ZippedBuffer::setCompressedData(QByteArray &compressedData)
{
    this->compressedData_ = compressedData;
}

void ZippedBuffer::write(QDataStream &stream)
{
    stream << relativeFilePath_ << compressedData_;
}

void ZippedBuffer::read(QDataStream &stream)
{
    stream >> relativeFilePath_ >> compressedData_;
}

QString ZippedBuffer::getRelativePath()
{
    return relativeFilePath_;
}
QByteArray ZippedBuffer::getCompressedDatas()
{
    return compressedData_;
}
