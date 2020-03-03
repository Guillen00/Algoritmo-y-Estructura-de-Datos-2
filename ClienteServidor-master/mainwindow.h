/**@Guille00
  *@data 02/03/2020
  *@brief Descripción: A continuación se describe la clase QDrawLine, la cual esta conectada con ClienteSocket y con la interfase del cliente.
  */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPixmap>
#include <QPaintEvent>
#include <QMainWindow>

#include <string>

/**Se añaden librerias de las cuales podremos utilizar metodos para dibujar en pantalla y el uso de la interfase del cliente
 * también se definen variables las cuales se utilizarán en el archivp cpp
 *
 */

QT_BEGIN_NAMESPACE
namespace Ui { class QDrawLine; }
QT_END_NAMESPACE

class ClienteSocket;

class QDrawLine : public QMainWindow //QWidget , paintWidget
{
    Q_OBJECT

public:
    QDrawLine(QWidget *parent = nullptr);
    ~QDrawLine();

private:
    Ui::QDrawLine *ui;
    QPixmap *m_nPTargetPixmap;

    ClienteSocket *mClienteSocket;
    ClienteSocket *makeSocket();

protected:
    void closeEvent(QCloseEvent *event);
/**Se utiliza para dibujar en pantalla
  *
  */
protected:
    void paintEvent(QPaintEvent *e);

    /**Se utiliza para crear los componentes del grafo
      *
      */
public:
    void nodo(int x,int y ,std::string t);
    void arista(int x1,int y1,int x2,int y2,int peso);
    void dijkstra();
    void grafocreado();
    void aux(int peso,int x1,int y1,int x2,int y2);

private slots:

    void on_dikstra_clicked();
    void on_conectar_clicked();
};
#endif // QDRAWLINE_H
