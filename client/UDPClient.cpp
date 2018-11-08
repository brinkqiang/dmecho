//
// Created by jorgen on 16.10.18.
//

#include "UDPClient.h"
#include "Exceptions.h"

UDPClient::UDPClient(const std::string &serverAddress, short port) : AbstractClient(serverAddress, port) {}

void UDPClient::sendMessage(std::string message) {
    auto bytesSent = ::sendto(this->clientSocket, message.data(), message.length(), 0,
            reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress));

    if (bytesSent < 0) {
        throw ClientException("Connection to the server closed");
    }
}

void UDPClient::connect() {
    // Do nothing
}

int UDPClient::createClientSocket() {
    int c = ::socket(AF_INET, SOCK_DGRAM, 0);

    if (c < 0) {
        throw ClientInitializationException("Failed to init client socket: " + std::to_string(errno));
    }

    return c;
}

std::string UDPClient::receiveMessage() {
    char buffer[Sockets::getMaxBufferLength() + 1];
    socklen_t addressLength = sizeof(serverAddress);

    auto receivedBytes = ::recvfrom(this->clientSocket, buffer, Sockets::getMaxBufferLength() + 1, 0,
            reinterpret_cast<sockaddr*>(&serverAddress), &addressLength);

    if (receivedBytes < 0) {
        throw ClientException("Connection the server closed");
    }

    buffer[receivedBytes] = '\0';

    return std::string(buffer);
}
