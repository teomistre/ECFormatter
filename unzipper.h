#ifndef UNZIPPER_H
#define UNZIPPER_H
#include <QThread>
#include "zippedbufferpool.h"

/**
 * @brief The Unzipper class used to uncompress files from an .ecf file.
 * Herits from QThread
 */
class Unzipper : public QThread
{
public:
    /**
     * @brief Unzipper when started, the unzipper grabs a compressed
     * file from a ZippedBufferPool, then uncompress the content
     * of a file and write using relative path.
     * @param zbPool the pool of compressed files see ZippedBufferPool for more
     * @param folder used to write uncompressed files
     */
    Unzipper(ZippedBufferPool &zbPool, const QString &folder);
    /**
     * @brief run the Unzipper, grabs ZippedBuffer from the ZippedBufferPool
     * then call the uncompressFile(); methods
     */
    virtual void run();
private:
    /**
     * @brief uncompressFile uncompress the content of the ZippedBuffer
     * and write it using relative file path
     * @param zb the ZippedBuffer to uncompress
     */
    void uncompressFile(ZippedBuffer &zb);
    /**
     * @brief getAbsolutePath combining extract folder and relative file path
     * to return absolute path
     * @param file_name the relative file path
     * @return the absolute path of the file
     */
    QString getAbsolutePath(const QString &file_name);
    /**
     * @brief makePath building the path (folders) for the file
     * @param filename the relative path of the file
     */
    void makePath(const QString &filename);
    /**
     * @brief zbPool_ the ZippedBufferPool of ZippedBuffer to uncompress
     */
    ZippedBufferPool &zbPool_;
    /**
     * @brief extractFolder_ the folder to start extraction
     */
    QString extractFolder_;
};

#endif // UNZIPPER_H
