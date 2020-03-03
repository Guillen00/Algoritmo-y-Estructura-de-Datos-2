/**@Guille00
  *@data 02/03/2020
  *@brief Descripción: A continuación se realiza la especificación de las funciones que se declararon en el documento servidorsocket.h
  */

#include "servidorsocket.h"
#include "clientesocket.h"


/**
 * @brief ServidorSocket::ServidorSocket , Se definen las variables de escuchando que funciona para ver si esta esperando un mensaje y puerto para saber el puerto habilitado.
 * @param parent
 */

ServidorSocket::ServidorSocket(QObject *parent) : QTcpServer { parent }
{
    mPuerto = 0;
    mEscuchando = false;
}

/**
 * @brief ServidorSocket::~ServidorSocket , al cerrar la aplicación se eliminan los clientes conectados
 */

ServidorSocket::~ServidorSocket()
{
    qDeleteAll(mClientes);
}

/**
 * @brief ServidorSocket::inicia , se habilita el escuchando , confirmando que esta esperando menaje
 */

void ServidorSocket::inicia()
{
    if (!mEscuchando)
    {
        mEscuchando = listen(QHostAddress::Any, mPuerto);
    }
}

/**
 * @brief ServidorSocket::setPuerto, cambia la variable por el puerto al cual se quiere hablitar para la conección
 * @param puerto
 */

void ServidorSocket::setPuerto(quint16 puerto)
{
    mPuerto = puerto;
}

/**
 * @brief ServidorSocket::clientes , se crea una lista que contiene a todos los clientes conectados
 * @return
 */

QList<ClienteSocket *> ServidorSocket::clientes() const
{
    return mClientes;
}

/**
 * @brief ServidorSocket::enviaMensaje , envia el mensaje hacia el cliente .
 * @param enumeracion
 * @param mensaje
 * @param cliente
 */

void ServidorSocket::enviaMensaje(int enumeracion, const QString &mensaje, ClienteSocket *cliente)
{
    cliente->enviaMensaje(enumeracion, mensaje);
}


/**
 * @brief ServidorSocket::desconectaClientes , elimina la concección de los clientes
 */

void ServidorSocket::desconectaClientes()
{
    const int nClientes = mClientes.size();
    for (int iCliente = 0; iCliente < nClientes; ++iCliente)
    {
        mClientes.at(iCliente)->disconnectFromHost();
    }
}

/**
 * @brief ServidorSocket::incomingConnection , añade un nuevo cliente a la lista de clientes.
 * @param handle
 */

void ServidorSocket::incomingConnection(qintptr handle)
{
    ClienteSocket *cliente = makeCliente(handle);
    mClientes.append(cliente);
    emit clienteConectado(cliente);
}

/**
 * @brief ServidorSocket::makeCliente , se conecta con el cliente y espera a recibir un mensaje.
 * @param handle
 * @return
 */

ClienteSocket *ServidorSocket::makeCliente(qintptr handle)
{
    ClienteSocket *cliente = new ClienteSocket;
    cliente->setSocketDescriptor(handle);

    connect(cliente, &ClienteSocket::desconectado, this, [&](ClienteSocket *socket)
    {
        emit clienteDesconectado(socket);
    });

    connect(cliente, &ClienteSocket::mensajeRecibido, this,
            [&](int enumeracion, const QString &mensaje, ClienteSocket *socket)
    {
        emit mensajeRecibido(enumeracion, mensaje, socket);
    });

    return cliente;
}
