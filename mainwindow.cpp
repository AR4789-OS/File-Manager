#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setWindowFlags(Qt::Widget);
    setParent(0); // Create TopLevel-Widget
    setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(44, 151, 241, 255), stop:1 rgba(98, 64, 232, 255));");

    ui->tabWidget->setTabsClosable(true);
    ui->tabWidget->setMovable(true);

    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(new TabWidget, tr("Drives"));
    ui->tabWidget->removeTab(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget ->addTab(new TabWidget, tr("Drives"));
}



void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

