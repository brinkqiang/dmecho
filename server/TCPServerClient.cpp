//
// Created by jorgen on 16.10.18.
//

#include "TCPServerClient.h"

TCPServerClient::TCPServerClient(sockaddr *address, int clientSocket)
    : AbstractServerClient(address), clientSocket(clientSocket) {

}

int TCPServerClient::getClientSocket() const {
    return clientSocket;
}

void TCPServerClient::sendMessage(int serverSocket, std::string message) const {
    ::send(this->clientSocket, message.data(), message.length(), 0);
}
