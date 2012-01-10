#include <QtGui/QApplication>
#include "xmpp.h"
//#include <>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    xmpp w;
    w.show();

    return a.exec();
}
