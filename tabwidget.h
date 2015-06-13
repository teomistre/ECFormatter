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
    void on_folderToCompress_clicked();
      void selectFolder();




      void on_locationFileToCompress_clicked();

      void on_pushButton_clicked();

      void on_selectFileEcf_clicked();

      void on_pathFolderUncompress_clicked();

      void on_uncompress_clicked();

      void on_spinBox_valueChanged(int arg1);

signals:
    void directoryChanged( const QDir &directory );
public slots:
    void validateFolder();


private:
    Ui::TabWidget *ui;
    QDir currentFolder_;
    EpsiFileCompressor efc_;
};

#endif // TABWIDGET_H
