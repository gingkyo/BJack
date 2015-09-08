#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::connectListener(){
    connect(manager,SIGNAL(sendHttpStatusCode(int,QByteArray)),this,SLOT(showCard(int,QByteArray)));
}
void MainWindow:: showCard(int statusCode,QByteArray data){
    if(statusCode==200){
        qDebug()<<"**THIS";
        //ui->textEdit->setText(data);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
