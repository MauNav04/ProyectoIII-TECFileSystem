#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "../Headers/ConnectionManager.h"


ConnectionManager::ConnectionManager()
{
    // Crear un socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cout << "Error al crear el socket" << std::endl;
    }
    else {
        // Agregar el IP y puerto al socket
        port = 54000; // Puerto
        ipAddress = "127.0.0.1"; // Localhost
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

        //	Conectarse al servidor
        connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
        if (connectRes == -1) {
            std::cout << "Error al conectarse al servidor" << std::endl;
        }
//        else {
//            std::string respuestaServer;
//
//            std::cin >> respuestaServer;
//            respuestaServer = mandarPeticion("{\"petition\" : \"addBook\", \"bookTitle\" : \"Pantalones Cortos\", \"bookAuthor\" : \"Lara Rios\", \"bookPath\" : \"books/cortos.txt\"}");
//            std::cout << respuestaServer << std::endl;
//
//            std::cin >> respuestaServer;
//            respuestaServer = mandarPeticion("{\"petition\" : \"addBook\", \"bookTitle\" : \"Harry Potter\", \"bookAuthor\" : \"J. K. Rowling\", \"bookPath\" : \"books/potter.txt\"}");
//            std::cout << respuestaServer << std::endl;
//
//            //	Close the socket
//                  (ver destructor en cesearch.cpp)
//            close(sock);
//        }
    }
}

std::string ConnectionManager::mandarPeticion(std::string mensajeCliente) {

    // Enviar al servidor
    sendRes = send(sock, mensajeCliente.c_str(), mensajeCliente.size() + 1, 0);
    if (sendRes == -1) {
        std::cout << "No se pudo enviar al servidor!\r\n";
    }
    else {
        // Esperar la respuesta del servidor
        memset(buf, 0, 4096);
        bytesReceived = recv(sock, buf, 4096, 0);
        if (bytesReceived == -1) {
            std::cout << "Hubo un error con la respuesta del servidor\r\n";
        }
        else {
            // Mostrar la respuesta
            return std::string(buf, bytesReceived);
        }
    }

    return NULL;
}

int ConnectionManager::getSock() const {
    return sock;
}

