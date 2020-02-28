#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include<time.h>
#include <iostream>
#include "grafo.h"
#include <string>
#include <queue>
#include <list>
#include <stack>


Grafo  C;

QDrawLine::QDrawLine(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QDrawLine)
{
    ui->setupUi(this);
    m_nPTargetPixmap = new QPixmap(500,500);
    m_nPTargetPixmap->fill(Qt::white);

}

QDrawLine::~QDrawLine()
{
    delete ui;
}



void QDrawLine::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter painter(this);
    painter.drawPixmap(0, 0, *m_nPTargetPixmap);
}


void QDrawLine::nodo(int x,int y,string t){
    QPainter PixmapPainter(m_nPTargetPixmap);
    QPen pen(Qt::black);
    PixmapPainter.background();
    PixmapPainter.setPen(pen);
    PixmapPainter.drawEllipse(x,y,20,20);
    PixmapPainter.drawText(x,y-5 ,QString::fromStdString(t));
    update();
}

void QDrawLine::on_botoncrear_clicked()
{
    m_nPTargetPixmap->fill(Qt::white);

    grafocreado();
    update();
}

int peso;

void QDrawLine::arista(int x1,int y1,int x2,int y2){
    QPainter PixmapPainter(m_nPTargetPixmap);
    QPen pen(Qt::black);
    PixmapPainter.setPen(pen);
    PixmapPainter.drawLine(x1,y1,x2,y2);
    peso=(rand()%19+1);
    PixmapPainter.drawText((x2+x1)/2,abs(y1+y2)/2,QString::number(peso));
    update();
}
void QDrawLine::on_dikstra_clicked()
{
    dijkstra();
}



void QDrawLine::dijkstra(){
    QString name1,name2;
    name1 = ui->vertice1->text();
    name2 = ui->vertice2->text();
    cout<<name1.toStdString()+"   "+name2.toStdString()<<endl;
    cout <<"Paso por aca"<<endl;
    cout <<C.Tamano()<<endl;
    C.Dijkstra(C.getvertice(name1.toStdString()),C.getvertice(name2.toStdString()));


}
void QDrawLine::grafocreado(){
    C.Inicializa();
    C.insertarvertice("H");
    nodo(30,250,"H");
    C.insertarvertice("A");
    nodo(120,100,"A");
    C.insertarvertice("D");
    nodo(120,350,"D");
    C.insertarvertice("B");
    nodo(180,250,"B");
    C.insertarvertice("C");
    nodo(240,80,"C");
    C.insertarvertice("G");
    nodo(240,350,"G");
    C.insertarvertice("E");
    nodo(340,250,"E");
    C.insertarvertice("F");
    nodo(360,100,"F");
    aux("H","A",10,30+10,250+10,120+10,100+10);
    aux("H","F",9,30+10,250+10,360+10,100+10);
    aux("H","B",6,30+10,250+10,180+10,250+10);
    aux("H","G",3,30+10,250+10,240+10,350+10);
    aux("H","D",14,30+10,250+10,120+10,350+10);
    aux("D","A",2,120+10,350+10,120+10,100+10);
    aux("D","B",8,120+10,350+10,180+10,250+10);
    aux("D","E",12,120+10,350+10,340+10,250+10);
    aux("A","B",3,120+10,100+10,180+10,250+10);
    aux("A","C",5,120+10,100+10,240+10,80+10);
    aux("B","G",6,180+10,250+10,240+10,350+10);
    aux("B","C",5,180+10,250+10,240+10,80+10);
    aux("B","E",4,180+10,250+10,340+10,250+10);
    aux("C","F",7,240+10,80+10,360+10,100+10);
    aux("C","G",9,240+10,80+10,240+10,350+10);
    aux("C","E",1,240+10,80+10,340+10,250+10);
    aux("G","E",7,240+10,350+10,340+10,250+10);

}
void QDrawLine::aux(std::string uno, std::string dos ,int peso,int x1,int y1,int x2, int y2){
    C.insertararista(C.getvertice(uno),C.getvertice(dos),peso);
    C.insertararista(C.getvertice(dos),C.getvertice(uno),peso);
    arista(x1,y1,x2,y2);
}
