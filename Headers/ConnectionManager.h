//
// Created by mavros on 26/6/21.
//

#ifndef PROYECTOIII_TECFILESYSTEM__CONNECTIONMANAGER_H
#define PROYECTOIII_TECFILESYSTEM__CONNECTIONMANAGER_H

#include <netdb.h>
#include <arpa/inet.h>

/**
 * Encargado de la conexión cliente/servidor con sockets
 */
class ConnectionManager {

private:

    /**
     * Socket
     */
    int sock;

    /**
     * Puerto
     */
    int port;

    /**
     * Envía datos al servidor
     */
    int sendRes;

    /**
     * Recibe bytes del servidor
     */
    int bytesReceived;

    /**
     * Diercción IP
     */
    std::string ipAddress;

    /**
     * Pista
     */
    sockaddr_in hint;

    /**
     * Define conexión entre ambos
     */
    int connectRes;

    /**
     * Define el tiempo de buffer
     */
    char buf[4096];

public:

    /**
     * Constructor de la conexión con sockets
     */
    ConnectionManager();

    /**
     * Uzado para guardar datos en el servidor
     * @param mensajeCliente datos a guardar
     * @return null
     */
    std::string mandarPeticion(std::string mensajeCliente);

    /**
     * Getter del socket
     * @return socket
     */
    int getSock() const;

};

#endif //PROYECTOIII_TECFILESYSTEM__CONNECTIONMANAGER_H
