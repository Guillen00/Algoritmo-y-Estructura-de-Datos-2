/**@Guille00
  *@data 02/03/2020
  *@brief Descripción: A continuación se realiza la inicialización de las interfase tanto la del cliente como la del servidor
  */

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
