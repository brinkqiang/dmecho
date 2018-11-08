#include <utility>

//
// Created by jorgen on 16.10.18.
//

#include "AbstractClient.h"

AbstractClient::AbstractClient(std::string serverAddress, short port) : serverAddressString(serverAddress) {
    this->serverAddress = Sockets::parseIPv4Address(std::move(serverAddress));
    this->serverAddress.sin_family = AF_INET;
    this->serverAddress.sin_port = htons(static_cast<uint16_t>(port));
}

void AbstractClient::initialize() {
    this->clientSocket = this->createClientSocket();
    this->connect();
}

AbstractClient::~AbstractClient() {
    ::shutdown(this->clientSocket, SHUT_RDWR);
    close(this->clientSocket);
}
