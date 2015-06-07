#ifndef ZIPPEDBUFFERPOOL_H
#define ZIPPEDBUFFERPOOL_H
#include <QPair>
#include <QWaitCondition>
#include <QMutex>
#include <QListData>
#include "zippedbuffer.h"

/**
 * @brief The ZippedBufferPool class represents groups of ZippedBuffer
 */
class ZippedBufferPool
{
public:
    /**
     * @brief ZippedBufferPool is used to store ZippedBuffer
     * before being writed to an .ecf file or before being
     * uncompressed
     */
    ZippedBufferPool();
    /**
     * @brief put a ZippedBuffer in the pool
     * @param zb the ZippedBuffer
     * @note this method will wake one thread
     */
    void put(ZippedBuffer &zb);
    /**
     * @brief tryGet return a QPair<bool,ZippedBuffer>
     * grabs a ZippedBuffer in the list, if none are avaible
     * waits, until a new one is put or if the setDone(); method
     * is called
     * @return the QPair
     * @note this method is thread safe and contains and QWaitCondition
     */
    QPair<bool,ZippedBuffer> tryGet();
    /**
     * @brief setDone signifed to the pool that no more ZippedBuffer
     * will be added;
     * @note this method will wake all the waitings threads
     */
    void setDone();
    /**
     * @brief done means that the pool will no longer receive files
     * @return true if pool is done, otherwise false;
     */
    bool done();
private:
    /**
     * @brief filePoolIsDone_ a boolean to know if pool is done
     */
    bool filePoolIsDone_;
    /**
     * @brief mutex_ used to access ZippedBuffer
     */
    QMutex mutex_;
    /**
     * @brief condition_ to wait for others ZippedBuffer to be added
     */
    QWaitCondition condition_;
    /**
     * @brief _zippedBuffers the list of ZippedBuffer contained in the pool
     */
    QList<ZippedBuffer> _zippedBuffers;
};

#endif // ZIPPEDBUFFERPOOL_H
