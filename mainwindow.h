#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connectionmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ConnectionManager* manager;
    void connectListener();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void showCard(int,QByteArray);
};



#endif // MAINWINDOW_H
