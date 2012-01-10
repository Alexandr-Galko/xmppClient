#include "xmpp.h"
#include "ui_xmpp.h"

xmpp::xmpp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::xmpp)
{
    ui->setupUi(this);
    setConnect();
}

xmpp::~xmpp()
{
    delete ui;
}

void xmpp::readSocket()
{
    QDataStream stream(tcpSocket);
    qDebug()<<"socket: "<<tcpSocket->readAll();
}
void xmpp::setConnect()
{

//    test14060zzz@xmpp.ru
//   a105555
    tcpSocket = new QTcpSocket(this);
    qDebug()<<"connect";
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readSocket()));
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(connection()));
    tcpSocket->connectToHost("jabber.ru",5222);
}
void xmpp::connection()
{
    qDebug()<<"+conected";
    tcpSocket->write("<?xml version='1.0'?>"
                     "<stream:stream to='jabber.ru' "
                         "xmlns='jabber:client' "
                         "xmlns:stream='http://etherx.jabber.org/streams' "
                         "version='1.0'>");
}
