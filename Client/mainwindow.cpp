#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBuffer>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    socket = new QTcpSocket();
    socket->connectToHost("127.0.0.1", 2022);
    ui->pushButton->setDisabled(true);
}


void MainWindow::on_pushButton_2_clicked()
{
    QFile file("C:/Users/yupi-/Desktop/New folder (2)/Untitled.png");
    file.open(QIODevice::ReadOnly);
    QByteArray q = file.readAll();
    socket->write(q);
}


