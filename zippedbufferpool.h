#ifndef ZIPPEDBUFFERPOOL_H
#define ZIPPEDBUFFERPOOL_H
#include <QPair>
#include <QWaitCondition>
#include <QMutex>
#include <QListData>
#include "zippedbuffer.h"

class ZippedBufferPool
{
public:
    ZippedBufferPool();
    void put(ZippedBuffer &zb);
    QPair<bool,ZippedBuffer> tryGet();
    void setDone();
    bool done();
private:
    bool filePoolIsDone_;
    QMutex mutex_;
    QWaitCondition condition_;
    QList<ZippedBuffer> _zippedBuffers;
};

#endif // ZIPPEDBUFFERPOOL_H
