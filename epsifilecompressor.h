#ifndef EPSIFILECOMPRESSOR_H
#define EPSIFILECOMPRESSOR_H
#include <QString>
/**
 * @brief The EpsiFileCompressor class used to (un)compress the file/folder
 */
class EpsiFileCompressor
{
public:
    /**
     * @brief EpsiFileCompressor expose the main method to compress or
     * uncompress files and folder. The number of thread used by the program
     * must be set in the constructor of the file.
     * @param nbThreads is the number of threads used during execution
     */
    EpsiFileCompressor(const int &nbThreads);
    /**
     * @brief compress in chage of compression of the folder into an .ecf file
     * @param folder the folder to compress
     * @param ecfFileName the absolute path of the .ecf file to create
     */
    void compress(const QString &folder, const QString &ecfFileName);
    /**
     * @brief uncompress the .ecf file into a specific folder
     * @param ecfFileName the absolute path of the .ecf file to uncompress
     * @param folder where to uncompress the content of the ecf file
     */
    void uncompress(const QString &ecfFileName, const QString &folder);
private:
    /**
     * @brief nbThreads_ the number of threads used during execution
     */
    int nbThreads_;
};

#endif // EPSIFILECOMPRESSOR_H
