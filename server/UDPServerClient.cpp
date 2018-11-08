//
// Created by jorgen on 16.10.18.
//

#include "UDPServerClient.h"

void UDPServerClient::sendMessage(int serverSocket, std::string message) const {
    ::sendto(serverSocket, message.data(), message.length(), 0,
            this->address, sizeof(*(this->address)));
}

UDPServerClient::UDPServerClient(sockaddr *address) : AbstractServerClient(address) {}
