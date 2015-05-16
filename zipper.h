#ifndef ZIPPER_H
#define ZIPPER_H
#include <QThread>
#include "filepool.h"
#include "zippedbufferpool.h"

class Zipper: public QThread
{
public:
    Zipper(FilePool &filePool, ZippedBufferPool &zpPool);
    virtual void run();
private:
    void compressFile(const QString &file_name);
    QString getRelativePath(const QString &file_name);
    FilePool &filePool_;
    ZippedBufferPool &zpPool_;
};

#endif // ZIPPER_H
