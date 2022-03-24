#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMainWindow>
#include <QBuffer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QTcpServer* pServer;
    quint16 m_nNextBlockSize;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void startServer();
    void readyRead();

private slots:
    void on_pushButton_clicked();
    void newClientConnection();
    void socketReadyRead();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
