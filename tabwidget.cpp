#include "tabwidget.h"
#include "ui_tabwidget.h"
#include "epsifilecompressor.h"
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

TabWidget::TabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabWidget),
    currentFolder_("C:\\"),
    efc_(2)
{
    ui->setupUi(this);
    ui->spinBox->setValue(efc_.nbThreads());
}

TabWidget::~TabWidget()
{
    delete ui;
}

void TabWidget::on_folderToCompress_clicked()
{
    QFileDialog dialog;

    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly);
    dialog.setDirectory(currentFolder());
    if( dialog.exec() == QFileDialog::Accepted ) {
       QString path = dialog.directory().absolutePath();
       path.replace("/","\\");
       ui->folderSource->setText(path);
        currentFolder_ = dialog.directory();
        emit directoryChanged( currentFolder_ );
    }

}

void TabWidget::validateFolder() {

}

void TabWidget::selectFolder() {


}

const QDir &TabWidget::currentFolder()const {
    return currentFolder_;
}

void TabWidget::on_locationFileToCompress_clicked()
{
    QFileDialog dialog;

    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly);
    dialog.setDirectory(currentFolder());
    if( dialog.exec() == QFileDialog::Accepted ) {
        QString path = dialog.directory().absolutePath()+"\\file.ecf";
        path.replace("/","\\");
       ui->locationFileCompress->setText(path);
       currentFolder_ = dialog.directory();
       emit directoryChanged( currentFolder_ );
    }
}

void TabWidget::on_pushButton_clicked()
{
    QString folderSource(ui->folderSource->text());
    QString fileCompress(ui->locationFileCompress->text());
    efc_.compress(folderSource,fileCompress);
}

void TabWidget::on_selectFileEcf_clicked()
{
    QFileDialog dialog;
    QString filePath;
    filePath = dialog.getOpenFileName(
                          this,
                          "Ouvrir un fichier ecf",
                          currentFolder().absolutePath(),
                          "ECF (*.ecf)");
    filePath.replace("/","\\");
     ui->fileECF->setText(filePath);
     currentFolder_ = dialog.directory();
     emit directoryChanged( currentFolder_ );
}

void TabWidget::on_pathFolderUncompress_clicked()
{
    QFileDialog dialog;

    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly);
    dialog.setDirectory(currentFolder());
    if( dialog.exec() == QFileDialog::Accepted ) {
        QString filePath=dialog.directory().absolutePath();
        filePath.replace("/","\\");
       ui->folderUncompress->setText(filePath);
       currentFolder_ = dialog.directory();
       emit directoryChanged( currentFolder_ );
    }
}

void TabWidget::on_uncompress_clicked()
{
    QString fileName(ui->fileECF->text());
    QString folderUnCompress(ui->folderUncompress->text());
    efc_.uncompress(fileName,folderUnCompress);
}

void TabWidget::on_spinBox_valueChanged(int nbThread)
{
    efc_.setNbThreads(nbThread);
    ui->spinBox->setValue(nbThread);
}
