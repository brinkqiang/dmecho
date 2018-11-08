//
// Created by jorgen on 16.10.18.
//

#include "TCPClient.h"
#include "Exceptions.h"

TCPClient::TCPClient(const std::string &serverAddress, short port)
    : AbstractClient(serverAddress, port) {}

void TCPClient::sendMessage(std::string message) {
    auto bytesSent = ::send(this->clientSocket, message.data(), message.length(), 0);

    if (bytesSent < 0) {
        throw ClientException("Connection to the server closed");
    }
}

void TCPClient::connect() {
    int res = ::connect(this->clientSocket, reinterpret_cast<sockaddr*>(&serverAddress),
            sizeof(this->serverAddress));

    if (res < 0) {
        throw ClientConnectionException("Failed to connect to " + this->serverAddressString);
    }
}

int TCPClient::createClientSocket() {
    int c = ::socket(AF_INET, SOCK_STREAM, 0);

    if (c < 0) {
        throw ClientInitializationException("Failed to init client socket: " + std::to_string(errno));
    }

    return c;
}

std::string TCPClient::receiveMessage() {
    char buffer[Sockets::getMaxBufferLength() + 1];

    auto receivedBytes = ::recv(this->clientSocket, buffer, Sockets::getMaxBufferLength() + 1, 0);

    if (receivedBytes <= 0) {
        throw ClientException("Connection the server closed");
    }

    buffer[receivedBytes] = '\0';

    return std::string(buffer);
}
