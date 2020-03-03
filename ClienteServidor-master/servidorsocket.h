/**@Guille00
  *@data 02/03/2020
  *@brief Descripción: A continuación se describe la clase ServidorSocket , la cual se utiliza como servidor recibiendo y enviando informaciòn
  */

#ifndef SERVIDORSOCKET_H
#define SERVIDORSOCKET_H
#include <iostream>
#include <QTcpServer>

class ClienteSocket;

/**@brief Se comparte con QTcpServer y se crean los metodos básicos para la comunicación se cliente-servidor y sobre la conección con el clinete por medio de la
 * ip y el puerto habilitado
  *
  */

class ServidorSocket : public QTcpServer
{
    Q_OBJECT
public:
    ServidorSocket(QObject *parent = nullptr);
    ~ServidorSocket() override;
    void inicia();
    void setPuerto(quint16 puerto);
    QList<ClienteSocket *> clientes() const;
    void enviaMensaje(int enumeracion, const QString &mensaje, ClienteSocket *cliente);
    void eliminaCliente(ClienteSocket *socket);
    void desconectaClientes();
signals:
    void mensajeRecibido(int enumeracion, const QString &mensaje, ClienteSocket *socket);
    void clienteConectado(ClienteSocket *socket);
    void clienteDesconectado(ClienteSocket *socket);
protected:
    void incomingConnection(qintptr handle) override;
private:
    quint16 mPuerto;
    QList<ClienteSocket *> mClientes;
    ClienteSocket *makeCliente(qintptr handle);
    bool mEscuchando;
};

#endif // SERVIDORSOCKET_H
