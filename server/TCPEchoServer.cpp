//
// Created by jorgen on 15.10.18.
//

#include <thread>
#include <signal.h>

#include "TCPEchoServer.h"
#include "TCPServerClient.h"
#include "EchoTask.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

TCPEchoServer::TCPEchoServer(short port) : AbstractServer(port) {
}

void TCPEchoServer::start() {
    // Add an echo task to the server
    this->addServerTask(std::make_shared<EchoTask>(this->serverSocket));

    if (listen(this->serverSocket, SOMAXCONN) < 0) {
        if (errno == EADDRINUSE) {
            throw ServerPortBusy(this->port);
        }

        throw ServerException("Failed to start server on port " + std::to_string(this->port));
    }

    sockaddr_in clientAddr {};
    socklen_t len = sizeof(clientAddr);

    int clientSocket;

    std::string inputLine;

    while(true) {
        clientSocket = accept(this->serverSocket, reinterpret_cast<sockaddr *>(&clientAddr), &len);

        std::thread clientThread([&]() {
            this->processClient(clientSocket, reinterpret_cast<sockaddr *>(&clientAddr));
        });

        clientThread.detach();
    }
}

void TCPEchoServer::processClient(int clientSocket, sockaddr *clientAddr)
{
    ssize_t receivedBytes = 1;
    char buffer[Sockets::getMaxBufferLength() + 1];

    std::string address = Sockets::getAddressString(clientAddr);

    std::cout << "[TCP] Client " << address << " connected" << std::endl;

    while (receivedBytes > 0) {
        receivedBytes = recv(clientSocket, buffer, Sockets::getMaxBufferLength(), 0);

        buffer[receivedBytes] = '\0';

        // Process message
        this->processClientMessage(TCPServerClient(clientAddr, clientSocket), std::string(buffer));
    }

    std::cout << "[TCP] Client " << address << " disconnected" << std::endl;

    ::shutdown(clientSocket, SHUT_RDWR);
    close(clientSocket);
}

int TCPEchoServer::createServerSocket() {
    int s = socket(AF_INET, SOCK_STREAM, 0);

    if (s == -1) {
        throw ServerInitializationException("Failed to create the server socket: " + std::to_string(errno));
    }

    return s;
}

#pragma clang diagnostic pop