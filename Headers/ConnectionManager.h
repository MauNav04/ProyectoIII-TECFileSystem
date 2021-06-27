//
// Created by mavros on 26/6/21.
//

#ifndef PROYECTOIII_TECFILESYSTEM__CONNECTIONMANAGER_H
#define PROYECTOIII_TECFILESYSTEM__CONNECTIONMANAGER_H

#include <netdb.h>
#include <arpa/inet.h>

class ConnectionManager {

private:
    int sock;
    int port;
    int sendRes;
    int bytesReceived;
    std::string ipAddress;
    sockaddr_in hint;
    int connectRes;
    char buf[4096];

public:
    ConnectionManager();
    std::string mandarPeticion(std::string mensajeCliente);

    int getSock() const;

};

#endif //PROYECTOIII_TECFILESYSTEM__CONNECTIONMANAGER_H
