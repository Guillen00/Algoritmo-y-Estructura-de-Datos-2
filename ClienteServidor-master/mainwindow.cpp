/**@Guille00
  *@data 02/03/2020
  *@brief Descripción: A continuación se realiza la especificación de las funciones que se declararon en el documento mainwindow.h
  */

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
#include "clientesocket.h"
#include "enumeraciones.h"
#include <QDebug>

/**
 * @brief C , lo usamos para implementar los métodos de la clase grafo
 */

Grafo  C;


/**
 * @brief QDrawLine::QDrawLine Inicializa la interfase grafica y crea de una vez la representación del grafo
 * @param parent
 */

QDrawLine::QDrawLine(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QDrawLine)
{
    ui->setupUi(this);
    m_nPTargetPixmap = new QPixmap(500,400);
    m_nPTargetPixmap->fill(Qt::white);

    mClienteSocket = makeSocket();

    grafocreado();
    update();


}

/**
 * @brief QDrawLine::~QDrawLine , elimina la interfase cuando se cierra la aplicación
 */

QDrawLine::~QDrawLine()
{
    delete ui;
}

/**
 * @brief QDrawLine::closeEvent , se desconecta del servidor cuando se cierre la aplicación
 * @param event
 */

void QDrawLine::closeEvent(QCloseEvent *event)
{
    mClienteSocket->disconnectFromHost();
    QWidget::closeEvent(event);
}

/**
 * @brief QDrawLine::paintEvent , Nos permite tener un evento para porder dibujar en pantalla.
 * @param e
 */

void QDrawLine::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter painter(this);
    painter.drawPixmap(0, 0, *m_nPTargetPixmap);
}

/**
 * @brief QDrawLine::nodo , crea un nodo en el pixmap , le da medidas y coordenadas para posicionarse
 * @param x
 * @param y
 * @param t
 */

void QDrawLine::nodo(int x,int y,string t){
    QPainter PixmapPainter(m_nPTargetPixmap);
    QPen pen(Qt::black);
    PixmapPainter.background();
    PixmapPainter.setPen(pen);
    PixmapPainter.drawEllipse(x,y,20,20);
    PixmapPainter.drawText(x,y-5 ,QString::fromStdString(t));
    update();
}

/**
 * @brief QDrawLine::arista , dibuja las aristas en pantalla en el pixmap
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 * @param peso
 */

void QDrawLine::arista(int x1,int y1,int x2,int y2,int peso){
    QPainter PixmapPainter(m_nPTargetPixmap);
    QPen pen(Qt::black);
    PixmapPainter.setPen(pen);
    PixmapPainter.drawLine(x1,y1,x2,y2);
    PixmapPainter.drawText((x2+x1)/2,abs(y1+y2)/2,QString::number(peso));
    update();
}

/**
 * @brief QDrawLine::on_dikstra_clicked , Cuando se presiona el boton de Dijkstra se mandan los vertices al servidor y este nos envia la ruta más corta entre los vertices.
 */


void QDrawLine::on_dikstra_clicked()
{
    QString enviarvertices = ui->vertice1->text() + ui->vertice2->text();

    string pase[2];
    pase[0]= ui->vertice1->text().toStdString();
    pase[1]= ui->vertice2->text().toStdString();
    mClienteSocket->enviaMensaje(InfoQuery, enviarvertices);
    //dijkstra();
}

/**
 * @brief QDrawLine::dijkstra , leemos lo que se escribio en los espacios de la interfase que corresponden a los vertices para hacer la ruta más corta.
 */

void QDrawLine::dijkstra(){
    QString name1,name2;
    name1 = ui->vertice1->text();
    name2 = ui->vertice2->text();
    cout<<name1.toStdString()+"   "+name2.toStdString()<<endl;
    C.Dijkstra(C.getvertice(name1.toStdString()),C.getvertice(name2.toStdString()));


}

/**
 * @brief QDrawLine::grafocreado, crea el grafo por completo con las aristas y vertices para poder hacer uso de ellos
 */

void QDrawLine::grafocreado(){

    nodo(30,250,"H");
    nodo(120,100,"A");
    nodo(120,350,"D");
    nodo(180,250,"B");
    nodo(240,80,"C");
    nodo(240,350,"G");
    nodo(340,250,"E");
    nodo(360,100,"F");
    aux(10,30+10,250+10,120+10,100+10);
    aux(9,30+10,250+10,360+10,100+10);
    aux(6,30+10,250+10,180+10,250+10);
    aux(3,30+10,250+10,240+10,350+10);
    aux(14,30+10,250+10,120+10,350+10);
    aux(2,120+10,350+10,120+10,100+10);
    aux(8,120+10,350+10,180+10,250+10);
    aux(12,120+10,350+10,340+10,250+10);
    aux(3,120+10,100+10,180+10,250+10);
    aux(5,120+10,100+10,240+10,80+10);
    aux(6,180+10,250+10,240+10,350+10);
    aux(5,180+10,250+10,240+10,80+10);
    aux(4,180+10,250+10,340+10,250+10);
    aux(7,240+10,80+10,360+10,100+10);
    aux(9,240+10,80+10,240+10,350+10);
    aux(1,240+10,80+10,340+10,250+10);
    aux(7,240+10,350+10,340+10,250+10);

}

/**
 * @brief QDrawLine::aux , una función con el objetivo de crear las aristas de los mismos vertices con el mismo peso de ida y vuelta
 * @param peso
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 */

void QDrawLine::aux(int peso,int x1,int y1,int x2, int y2){
    arista(x1,y1,x2,y2,peso);
}


/**
 * @brief QDrawLine::on_conectar_clicked , cuando se presiona se lee la linea en la cual se ingresa la ip y el puerto para conectar
 * se envian los datos para poder conectar con el servidor
 */

void QDrawLine::on_conectar_clicked()
{
    QString ipServidor = ui->lineIP->text();
    quint16 puertoServidor = quint16(ui->linePUERTO->text().toUInt());

    if (ipServidor.isEmpty())
    {
        return;
    }
    if (puertoServidor == 0)
    {
        return;
    }

    mClienteSocket->setDireccionDelServidor(ipServidor);
    mClienteSocket->setPuertoDelServidor(puertoServidor);
    mClienteSocket->conectaConElServidor();
    ui->label_6->setText("Conectado");
}

/**
 * @brief QDrawLine::makeSocket , Metodo el cual conecta con el servidor para recibir el mensaje que el servidor mande y lo imprime en la etiqueta de resultado.
 * @return
 */

ClienteSocket *QDrawLine::makeSocket()
{
    ClienteSocket *socket = new ClienteSocket(this);

    connect(socket, &ClienteSocket::mensajeRecibido, this,
            [&](int enumeracion, const QString &mensaje, ClienteSocket *socket)
    {
        cout<<"paso lo"<<endl;
        (void) socket;
        if (enumeracion == InfoResponse)
        {
           ui->resultado->setText(mensaje);
        }
    });

    return socket;
}
