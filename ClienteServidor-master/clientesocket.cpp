/**@Guille00
  *@data 02/03/2020
  *@brief Descripción: A continuación se realiza la especificación de las funciones que se declararon en el documento .h
  */

#include "clientesocket.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>


/**Se importan librerias para manejar los documentos u información de una mejor manera.
  *El método ClienteSocket inicializa las variables y busca la conección con esas condiciones
  */
ClienteSocket::ClienteSocket(QObject *parent) : QTcpSocket { parent }
{
    mDireccionDelServidor = "";
    mPuertoDelServidor = 0;
    mConectado = false;

    connect(this, &ClienteSocket::readyRead, this, [&]()
    {
        QJsonDocument doc = QJsonDocument::fromJson(readAll());
        QJsonObject obj = doc.object();
        const int enumeracion = obj["enumeracion"].toInt();
        QString mensaje = obj["mensaje"].toString();
        emit mensajeRecibido(enumeracion, mensaje, this);
    });

    connect(this, &ClienteSocket::stateChanged, this, [&](QAbstractSocket::SocketState state)
    {
        if (state == QAbstractSocket::UnconnectedState)
        {
            emit desconectado(this);
        }
    });
}

/**Se envia mensaje desde el cliente hacia el servidor
  *
  */
void ClienteSocket::enviaMensaje(int enumeracion, const QString &mensaje)
{
    QJsonDocument doc;
    QJsonObject obj;
    obj["enumeracion"] = enumeracion;
    obj["mensaje"] = mensaje;
    doc.setObject(obj);
    write(doc.toJson(QJsonDocument::Compact));
}


/**Inicializa la variable que contiene la ip para conección
  *
  */
void ClienteSocket::setDireccionDelServidor(const QString &ip)
{
    mDireccionDelServidor = ip;
}

/**Inicializa la variable que contiene el puerto para conección
  *
  */

void ClienteSocket::setPuertoDelServidor(quint16 puerto)
{
    mPuertoDelServidor = puerto;
}


/**Realiza la conección con el servidor mandando la ip y el puerto
  *
  */

void ClienteSocket::conectaConElServidor()
{
    if (!mConectado)
    {
        connectToHost(mDireccionDelServidor, mPuertoDelServidor);
        mConectado = true;
    }
}
/**define la variable mId con ina variable qintptr
  *
  */
bool ClienteSocket::setSocketDescriptor(qintptr socketDescriptor,
                                          QAbstractSocket::SocketState state,
                                          QIODevice::OpenMode openMode)
{
    mId = QString::number(socketDescriptor);
    return QTcpSocket::setSocketDescriptor(socketDescriptor, state, openMode);
}
