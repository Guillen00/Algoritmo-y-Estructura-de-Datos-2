#include <QApplication>
#include "servidorwidget.h"
#include "clientewidget.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    ServidorWidget *servidor = new ServidorWidget;
    ClienteWidget *cliente = new ClienteWidget;
    QDrawLine *w = new QDrawLine;
    w->show();
    servidor->show();
    cliente->show();
    return a.exec();
}
