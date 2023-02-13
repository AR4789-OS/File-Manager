#include "tabwidget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_tabwidget.h"
#include <QDebug>

TabWidget::TabWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabWidget)
{
    ui->setupUi(this);

    QString sPath = "~/";

    filemodel = new QFileSystemModel(this);
    filemodel->setRootPath(sPath);

    ui->listView->setModel(filemodel);
}

TabWidget::~TabWidget()
{
    delete ui;
}

void TabWidget::on_listView_doubleClicked(const QModelIndex &index)
{
    QString sPath = filemodel->fileInfo(index).absoluteFilePath();
    if (filemodel->isDir(index)) {
        ui->listView->setRootIndex(filemodel->setRootPath(sPath));
    } else {
        QDesktopServices::openUrl(QUrl("file:///" + sPath));
    }
}

