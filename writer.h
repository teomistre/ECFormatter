#ifndef WRITER_H
#define WRITER_H
#include <QThread>
#include "zippedbufferpool.h"
#include "zippedbuffer.h"
#include <QDataStream>
#include <QFile>
/**
 * @brief The Writer class used to write the ZippedBuffer of a ZippedBufferPool
 * into an .ecf file. Herits from QThread
 */
class Writer : public QThread
{
public:
    /**
     * @brief Writer when started the writer start grabing compressed files
     * from the pool and write them into an .ecf file
     * @note Writer is a single-thread class
     * @param zbPool the pool of compressed files
     * @param fileName the file path of the .ecf to create
     */
    Writer(ZippedBufferPool &zbPool, const QString &fileName);
    /**
     * @brief run the Writer, grabs ZippedBuffer from the ZippedBufferPool
     * and puts them into a QDataStream
     */
    virtual void run();
private:
    /**
     * @brief write the .ecf file when all the ZippedBuffer in the pool have been put
     * into the QDataStream
     */
    void write();
    /**
     * @brief zpPool_ the ZippedBufferPool of ZippedBuffer to write
     */
    ZippedBufferPool &zpPool_;
    /**
     * @brief fileToWrite_ the path of the .ecf file to create
     */
    QFile fileToWrite_;
};

#endif // WRITER_H
