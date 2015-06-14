#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include <QWidget>
#include <QDir>
#include "epsifilecompressor.h"
class QLineEdit;
namespace Ui {
class TabWidget;
}

class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit TabWidget(QWidget *parent = 0);
     const QDir &currentFolder()const;
    ~TabWidget();

private slots:

     /**
     * @brief Select the folder that will be compress
     */
    void on_folderToCompress_clicked();

    /**
    * @brief select the location of the compressed file
    */
     void on_locationFileToCompress_clicked();

     /**
       * @brief Call the method to compress file to format .ecf
       * the default name of file is 'file.efc'
       */
      void on_pushButton_clicked();

      /**
        * @brief Select the ecf file that will be uncompress
        * we can select only  "*.ecf" files
        */
      void on_selectFileEcf_clicked();

      /**
       * @brief Select the location of the uncompressed file
       */
      void on_pathFolderUncompress_clicked();

      /**
       * @brief Call the uncompress method.
       */
      void on_uncompress_clicked();

      /**
       * @brief Change the number of threads that will execute
       * @param number of threads
       */
      void on_spinBox_valueChanged(int nbThread);

signals:
      /**
     * @brief Change the current directory
     * @param new directory
     */
    void directoryChanged( const QDir &directory );

private:
    Ui::TabWidget *ui;
    QDir currentFolder_;
    EpsiFileCompressor efc_;
};

#endif // TABWIDGET_H
