#ifndef UNZIPPER_H
#define UNZIPPER_H
#include <QThread>
#include "zippedbufferpool.h"

class Unzipper : public QThread
{
public:
    Unzipper(ZippedBufferPool &zbPool, const QString &folder);
    virtual void run();
private:
    void uncompressFile(ZippedBuffer &zb);
    QString getAbsolutePath(const QString &file_name);
    void makePath(const QString &filename);
    ZippedBufferPool &zbPool_;
    QString extractFolder_;
};

#endif // UNZIPPER_H
