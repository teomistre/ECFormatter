#ifndef WRITER_H
#define WRITER_H
#include <QThread>
#include "zippedbufferpool.h"
#include "zippedbuffer.h"

class Writer : public QThread
{
public:
    Writer(ZippedBufferPool &zbPool, const QString &fileName);
    virtual void run();
private:
    ZippedBufferPool &zpPool_;
    void Write();
    QString fileNameToWrite_;
};

#endif // WRITER_H
