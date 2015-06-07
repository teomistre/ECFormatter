#ifndef ZIPPER_H
#define ZIPPER_H
#include <QThread>
#include "filepool.h"
#include "zippedbufferpool.h"
/**
 * @brief The Zipper class used to compress files to an .ecf file.
 * Herits from QThread
 */
class Zipper: public QThread
{
public:
    /**
     * @brief Zipper when started, the zipped grabs an umcompressed
     * file from a FilePool, compress the content
     * of the file and its relative path into an ZippedBuffer and
     * finally put it into the ZippedBufferPool.
     * @param filePool the pool of files to compress
     * @param zpPool the pool of ZippedBuffer
     */
    Zipper(FilePool &filePool, ZippedBufferPool &zpPool);
    /**
     * @brief run the Zipper, starts grabing file from the pool and call
     * the compressFile(); method
     */
    virtual void run();
private:
    /**
     * @brief compressFile read the file and compress the datas
     * into a QByteArray usinq qCompress(); wrap it with the relative
     * path into a ZippedBuffer and put it into the pool
     * @param file_name the file path of file to compress
     */
    void compressFile(const QString &file_name);
    /**
     * @brief getRelativePath get the relative path of the file using extraction folder
     * @param file_name the absolute path of the file
     * @return the relative path
     */
    QString getRelativePath(const QString &file_name);
    /**
     * @brief filePool_ the pool of files to compress
     */
    FilePool &filePool_;
    /**
     * @brief zpPool_ the pool used to store ZippedBuffer
     */
    ZippedBufferPool &zpPool_;
};

#endif // ZIPPER_H
