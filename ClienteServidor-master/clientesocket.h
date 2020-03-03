/**@Guille00
  *@data 02/03/2020
  *@brief Descripción: A continuación se describe la clase ClienteSocket la cual tiene funciones para lograr concetarse con el servidor y poder tener una
  * comunicaciòn cliente-servidor
  */

#ifndef CLIENTESOCKET_H
#define CLIENTESOCKET_H
#include <iostream>
#include <QTcpSocket>

/**Se incluye la libreria QTcpSocket la cual nos permite aplicar la comunicación con los sockets, también se crean varios métodos para comunicarse con el servidor
 * tales como enviarle mensajes , recibirlos o abrir un puerto para la comunicación, a su vez se definieron algunas variables que se utilizarán en otro archivo
  *
  */

class ClienteSocket : public QTcpSocket
{
    Q_OBJECT
public:
    ClienteSocket(QObject *parent = nullptr);
    void enviaMensaje(int enumeracion, const QString &mensaje);
    void setDireccionDelServidor(const QString &ip);
    void setPuertoDelServidor(quint16 puerto);
    void conectaConElServidor();
    bool setSocketDescriptor(qintptr socketDescriptor, SocketState state = ConnectedState, OpenMode openMode = ReadWrite) override;

    QString id() const
    {
        return mId;
    }
signals:
    void mensajeRecibido(int enumeracion, const QString &mensaje, ClienteSocket *socket);
    void desconectado(ClienteSocket *socket);
private:
    QString mDireccionDelServidor;
    quint16 mPuertoDelServidor;
    bool mConectado;
    QString mId;
};

#endif // CLIENTESOCKET_H
