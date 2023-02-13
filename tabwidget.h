#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <QFileSystemModel>
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class TabWidget;
}

class TabWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TabWidget(QWidget *parent = nullptr);
    ~TabWidget();

private slots:
    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::TabWidget *ui;

    QFileSystemModel *filemodel;
};

#endif // TABWIDGET_H
