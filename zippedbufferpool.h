#ifndef ZIPPEDBUFFERPOOL_H
#define ZIPPEDBUFFERPOOL_H
#include <QPair>
#include <QWaitCondition>
#include "zippedbuffer.h"
#include <QListData>

class ZippedBufferPool
{
public:
    ZippedBufferPool();
    void put(ZippedBuffer &zb);
    QPair<bool,ZippedBuffer> tryGet();
    bool done();
private:
    QMutex mutex_;
    QWaitCondition condition_;
    QList<ZippedBuffer *> _zippedBuffers;
};

#endif // ZIPPEDBUFFERPOOL_H
