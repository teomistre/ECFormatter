#include "zippedbufferpool.h"

ZippedBufferPool::ZippedBufferPool()
{
    filePoolIsDone_ = false;
}

void ZippedBufferPool::put(ZippedBuffer &zb)
{
    QMutexLocker locker(&mutex_);
    this->_zippedBuffers.append(zb);
    condition_.wakeOne();
}

QPair<bool,ZippedBuffer> ZippedBufferPool::tryGet()
{
    ZippedBuffer emptyBuffer;
    QPair<bool,ZippedBuffer> pair(false,emptyBuffer);

    QMutexLocker locker(&mutex_);
    if (_zippedBuffers.isEmpty() == false)
    {
        pair.first = true;
        pair.second = _zippedBuffers.front();
        _zippedBuffers.pop_front();
    }
    else
    {
        if (!done())
        {            
            condition_.wait(&mutex_);
            if (_zippedBuffers.isEmpty() == false)
            {
                pair.first = true;
                pair.second = _zippedBuffers.front();
                _zippedBuffers.pop_front();
            }
        }
    }
    return pair;
}

void ZippedBufferPool::setDone()
{
    this->filePoolIsDone_ = true;
    condition_.wakeAll();
}

bool ZippedBufferPool::done()
{
    return filePoolIsDone_;
}
