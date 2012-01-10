#ifndef XMPP_H
#define XMPP_H

#include <QMainWindow>
#include <QtNetwork>
#include <QtGui>
#include <QDebug>

namespace Ui {
    class xmpp;
}

class xmpp : public QMainWindow
{
    Q_OBJECT

public:
    explicit xmpp(QWidget *parent = 0);
    ~xmpp();
private slots:
    void readSocket();
    void setConnect();
    void connection();

private:
    Ui::xmpp *ui;
    QTcpSocket *tcpSocket;
};

#endif // XMPP_H
