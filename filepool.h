#ifndef FILEPOOL_H
#define FILEPOOL_H
#include <QString>
#include <QStringList>
#include <QMutex>
/**
 * @brief The FilePool class represents group
 * of files to compress
 */
class FilePool
{
public:
    /**
     * @brief FilePool is lising all the file of the folder and all subfolders/files
     * @param folder from the files are listed
     */
    FilePool(const QString &folder);
    /**
     * @brief count the number of file in the pool
     * @return the number of file in the pool
     * @note This method is thread safe
     */
    int count();
    /**
     * @brief tryGetFile try to return a filename or an
     * empty string if none avalaible.
     * @return the file name or an empty string
     * @note This method is thread safe
     */
    QString tryGetFile() ;
    /**
     * @brief getFolderPath the folder path used for pooling
     * @return the folder path
     */
    QString getFolderPath();
private:
    /**
     * @brief findFileInFolderAndSubfolders initialize pool by indexing
     * recursivly folders and subfolders
     * @param folder to explore
     */
    void findFileInFolderAndSubfolders(const QString &folder);
    /**
     * @brief files_ list of the files contained in the pool
     */
    QStringList files_;
    /**
     * @brief mutex_ used for accessing files
     */
    QMutex mutex_;

    /**
     * @brief folderPath_ the folder to start indexing files
     */
    QString folderPath_;


};

#endif // FILEPOOL_H
