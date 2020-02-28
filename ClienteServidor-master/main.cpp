#include <QApplication>
#include "servidorwidget.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    ServidorWidget *servidor = new ServidorWidget;
    QDrawLine *w = new QDrawLine;
    w->show();
    servidor->show();
    return a.exec();
}
