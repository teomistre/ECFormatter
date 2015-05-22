#ifndef WRITER_H
#define WRITER_H
#include <QThread>
#include "zippedbufferpool.h"
#include "zippedbuffer.h"
#include <QDataStream>
#include <QFile>

class Writer : public QThread
{
public:
    Writer(ZippedBufferPool &zbPool, const QString &fileName);
    virtual void run();
private:
    ZippedBufferPool &zpPool_;
    void write();
    QFile fileToWrite_;
};

#endif // WRITER_H
