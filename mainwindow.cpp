#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QLabel>
#include <QPixmap>

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

void MainWindow::startServer()
{
    pServer = new QTcpServer();
    connect(pServer, SIGNAL(newConnection()), this,
            SLOT(newClientConnection()));
    pServer->listen(QHostAddress::Any, 2022);
    ui->textBrowser->append("Server started listening to port 2022");
}

void MainWindow::newClientConnection()
{
    QTcpSocket* client = pServer->nextPendingConnection();
    connect(client, &QTcpSocket::readyRead, this,
            &MainWindow::socketReadyRead);
    ui->textBrowser->append("A new client has connected !");
}

void MainWindow::socketReadyRead()
{
   QTcpSocket* client = (QTcpSocket*)QObject::sender();
   QByteArray ar = client->readAll();
   QPixmap p;
   p.loadFromData(ar, "PNG");
   ui->label_3->setPixmap(p);
}

void MainWindow::on_pushButton_clicked()
{
    MainWindow::startServer();
    ui->pushButton->setDisabled(true);
}

