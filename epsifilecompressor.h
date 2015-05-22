#ifndef EPSIFILECOMPRESSOR_H
#define EPSIFILECOMPRESSOR_H
#include <QString>

class EpsiFileCompressor
{
public:
    EpsiFileCompressor(const int &nbThreads);
    void compress(const QString &folder, const QString &ecfFileName);
    void uncompress(const QString &ecfFileName, const QString &folder);
private:
    int nbThreads_;
};

#endif // EPSIFILECOMPRESSOR_H
