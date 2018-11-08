#include <utility>

//
// Created by jorgen on 16.10.18.
//

#include "AbstractServer.h"
#include "AbstractServerClient.h"

AbstractServer::AbstractServer(short port) : port(port) {
}

void AbstractServer::bind() {
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_port = htons(static_cast<uint16_t>(port));
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    int result = ::bind(this->serverSocket, reinterpret_cast<const sockaddr *>(&address), sizeof(address));

    if (result == -1) {
        std::string message;

        if (errno == EACCES) {
            message = "can't use " + std::to_string(port) + " port. You need to be the super user!";
        } else if (errno == EADDRINUSE) {
            message = "port " + std::to_string(port) + " is already used!";
        } else {
            message = " error code is " + std::to_string(errno);
        }

        throw ServerInitializationException("Failed to bind server socket: " + message);
    }
}

void AbstractServer::initialize() {
    this->serverSocket = this->createServerSocket();
    this->bind();
}

void AbstractServer::processClientMessage(const AbstractServerClient &client, std::string message) {
    for (const auto &task : this->tasks) {
        task->processClientMessage(client, message);
    }
}

void AbstractServer::addServerTask(std::shared_ptr<ServerTaskInterface> task) {
    this->tasks.push_back(task);
}
