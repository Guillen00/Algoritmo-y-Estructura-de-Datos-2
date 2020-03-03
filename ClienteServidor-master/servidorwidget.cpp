/**@Guille00
  *@data 02/03/2020
  *@brief Descripción: A continuación se realiza la especificación de las funciones que se declararon en el documento servidowidget.h
  */

#include "servidorwidget.h"
#include "ui_servidorwidget.h"
#include "servidorsocket.h"
#include "clientesocket.h"
#include "enumeraciones.h"
#include <QInputDialog>
#include "grafo.h"
#include <iostream>

/**
 * @brief ServidorWidget::ServidorWidget , inicializa la interfase del servidor, deshabilita las ventanas en las cuales se mostrará conenido cundo este conectado con un cliente
 * @param parent
 */

ServidorWidget::ServidorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServidorWidget)
{
    ui->setupUi(this);
    mServidorSocket = makeServidor();
    ui->frame2->setDisabled(true);
    ui->frame3->setDisabled(true);
    ui->plaintextedit->setReadOnly(true);
}

/**
 * @brief g se inicializa la clase grafo para poder implementar sus metodos
 */

Grafo g;

ServidorWidget::~ServidorWidget()
{
    delete ui;
}

/**
 * @brief ServidorWidget::closeEvent , al cerrar la aplicación se desconectan las clases y cierra la interfase.
 * @param event
 */

void ServidorWidget::closeEvent(QCloseEvent *event)
{
    mServidorSocket->desconectaClientes();
    QWidget::closeEvent(event);
}

/**
 * @brief ServidorWidget::on_encenderButton_clicked , al presionar se recibe lo ingresado en la linea para puerto, y se hablita
 * ese puerto para poder hacer la conección
 */

void ServidorWidget::on_encenderButton_clicked()
{
    quint16 puerto = quint16(ui->puertoDeEscuchaLineedit->text().toUInt());

    if (puerto == 0)
    {
        return;
    }

    mServidorSocket->setPuerto(puerto);
    mServidorSocket->inicia();
    ui->frame2->setEnabled(true);
    ui->frame3->setEnabled(true);
}

/**
 * @brief ServidorWidget::makeServidor , conecta el servidor con el cliente y espera a recibir mensaje del cliente el cual lo manda a la función de Dijkstra.
 * @return
 */

ServidorSocket *ServidorWidget::makeServidor()
{
    ServidorSocket *servidor = new ServidorSocket(this);

    connect(servidor, &ServidorSocket::clienteConectado, this, [&](ClienteSocket *socket)
    {
        ui->clientesConectadosListwidget->addItem(socket->id());

    });


    connect(servidor, &ServidorSocket::mensajeRecibido, this,
            [&](int enumeracion, const QString &mensaje, ClienteSocket *socket)
    {
        (void) socket;
        if (enumeracion == InfoQuery)
        {
            ui->plaintextedit->appendPlainText(mensaje);


        }
            g.listaadyacencia();
            QString ruta = QString::fromStdString(g.Dijkstra(g.getvertice(mensaje.mid(0,1).toStdString()),g.getvertice(mensaje.mid(1,1).toStdString())));
            mServidorSocket->enviaMensaje(InfoResponse,ruta,socket);


    });

    return servidor;
}

/**
 * @brief ServidorWidget::on_clientesConectadosListwidget_clicked , envia un mensaje a todos los clientes conectados.
 * @param index
 */

void ServidorWidget::on_clientesConectadosListwidget_clicked(const QModelIndex &index)
{
    ClienteSocket *cliente = mServidorSocket->clientes().at(index.row());
    QString mensaje = QInputDialog::getText(this, "Mensaje", "Mensaje");
    if (!mensaje.isEmpty())
    {
        cliente->enviaMensaje(InfoResponse, mensaje);
    }
}

/**
 * @brief ServidorWidget::CrearGrafo , Crea un grafo predeterminado con los vertices y las aristas
 */

void ServidorWidget::CrearGrafo(){
    g.Inicializa();
    g.insertarvertice("H");
    g.insertarvertice("A");
    g.insertarvertice("D");
    g.insertarvertice("B");
    g.insertarvertice("C");
    g.insertarvertice("G");
    g.insertarvertice("E");
    g.insertarvertice("F");
    aristasdobles("H","A",10);
    aristasdobles("H","F",9);
    aristasdobles("H","B",6);
    aristasdobles("H","G",3);
    aristasdobles("H","D",14);
    aristasdobles("D","A",2);
    aristasdobles("D","B",8);
    aristasdobles("D","E",12);
    aristasdobles("A","B",3);
    aristasdobles("A","C",5);
    aristasdobles("B","G",6);
    aristasdobles("B","C",5);
    aristasdobles("B","E",4);
    aristasdobles("C","F",7);
    aristasdobles("C","G",9);
    aristasdobles("C","E",1);
    aristasdobles("G","E",7);


}

/**
 * @brief ServidorWidget::aristasdobles , una función la cual crea una arista en ambas direcciones con el mismo peso.
 * @param uno
 * @param dos
 * @param peso
 */

void ServidorWidget::aristasdobles(std::string uno, std::string dos, int peso){
    g.insertararista(g.getvertice(uno),g.getvertice(dos),peso);
    g.insertararista(g.getvertice(dos),g.getvertice(uno),peso);

}
