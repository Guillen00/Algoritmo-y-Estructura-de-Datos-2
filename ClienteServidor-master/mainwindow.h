#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPixmap>
#include <QPaintEvent>
#include <QMainWindow>

#include <string>


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
protected:
    void paintEvent(QPaintEvent *e);
public:
    void nodo(int x,int y ,std::string t);
    void arista(int x1,int y1,int x2,int y2,int peso);
    void dijkstra();
    void grafocreado();
    void aux(std::string uno, std::string dos,int peso,int x1,int y1,int x2,int y2);

private slots:

    void on_botoncrear_clicked();
    void on_dikstra_clicked();
    void on_conectar_clicked();
};
#endif // QDRAWLINE_H
