#ifndef ZIPPEDBUFFER_H
#define ZIPPEDBUFFER_H
#include <QString>


class ZippedBuffer
{
public:
    ZippedBuffer();
    void write(QDataStream &stream);
    void read(QDataStream &stream);
private:
    QString relativeFilePath_;
    QByteArray compressedData_;
};

#endif // ZIPPEDBUFFER_H
