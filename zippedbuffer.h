#ifndef ZIPPEDBUFFER_H
#define ZIPPEDBUFFER_H
#include <QString>

/**
 * @brief The ZippedBuffer class use to store path and datas of a file
 */
class ZippedBuffer
{
public:
    /**
     * @brief ZippedBuffer contains the relative path
     * and the compressed datas of a file to (un)compress
     */
    ZippedBuffer();
    /**
     * @brief setRelativePath set the relativeFilePath_ of the file
     * @param relativePath the relative path
     */
    void setRelativePath(const QString &relativePath);
    /**
     * @brief setCompressedData set the compressedData_ of the file
     * @param compressedData the compressed datas
     */
    void setCompressedData(QByteArray &compressedData);
    /**
     * @brief getRelativePath return the relativeFilePath_ of the file
     * @return the relative file path
     */
    QString getRelativePath();
    /**
     * @brief getCompressedDatas return the compressedData_ of the file
     * @return the compressed datas
     */
    QByteArray getCompressedDatas();
    /**
     * @brief write the content of the ZippedBuffer into a stream
     * @param stream to write the content
     */
    void write(QDataStream &stream);
    /**
     * @brief read the content of the stream to set the content of the ZippedBuffer
     * @param stream to read content from
     */
    void read(QDataStream &stream);
private:
    /**
     * @brief relativeFilePath_ the relative path of the file
     */
    QString relativeFilePath_;
    /**
     * @brief compressedData_ the compressed datas of the file
     */
    QByteArray compressedData_;
};

#endif // ZIPPEDBUFFER_H
