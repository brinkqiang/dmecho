//
// Created by jorgen on 16.10.18.
//

#include "EchoTask.h"

void EchoTask::processClientMessage(const AbstractServerClient &client, std::string message) {
    client.sendMessage(this->serverSocket, message);
}

EchoTask::EchoTask(int serverSocket) : serverSocket(serverSocket) {}
