#include "mainwindow.h"
#include <QApplication>
#include "connectionmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ConnectionManager* conn=new ConnectionManager();
    w.manager=conn;
    conn->sendPost("email","true");

    w.show();

    return a.exec();
}
