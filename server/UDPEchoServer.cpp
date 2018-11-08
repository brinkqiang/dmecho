
#include "UDPEchoServer.h"
#include "UDPServerClient.h"
#include "EchoTask.h"
#include <thread>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

UDPEchoServer::UDPEchoServer(short port)
    : AbstractServer(port) {
}

int UDPEchoServer::createServerSocket() {
    int s = ::socket(AF_INET, SOCK_DGRAM, 0);

    if (s < 0) {
        throw ServerInitializationException(
                "Failed to create the server socket: " + std::to_string(errno));
    }

    return s;
}

void UDPEchoServer::start() {
    
    this->addServerTask(std::make_shared<EchoTask>(this->serverSocket));

    
    sockaddr_in clientAddress {};
    socklen_t addressLength = sizeof(clientAddress);
    char buffer[Sockets::getMaxBufferLength() + 1];
    ssize_t receivedBytes = 0;

    while (true) {
        receivedBytes = recvfrom(this->serverSocket, buffer, Sockets::getMaxBufferLength(), 0,
                reinterpret_cast<sockaddr*>(&clientAddress), &addressLength);

        if (receivedBytes > 0) {
            std::cout << "[UDP] Received " << receivedBytes << " bytes from "
                << Sockets::getAddressString(&clientAddress) << std::endl;

            buffer[receivedBytes] = '\0';

            std::thread clientThread([&](){
                this->processClientMessage(UDPServerClient(reinterpret_cast<sockaddr*>(&clientAddress)),
                        std::string(buffer));
            });

            clientThread.detach();
        }
    }
}

#pragma clang diagnostic pop