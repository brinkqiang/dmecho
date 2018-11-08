//
// Created by jorgen on 16.10.18.
//

#ifndef ECHOAPP_TCPSERVERCLIENT_H
#define ECHOAPP_TCPSERVERCLIENT_H

#include "AbstractServerClient.h"

class TCPServerClient : public AbstractServerClient {
    int clientSocket;

public:
    TCPServerClient(sockaddr *address, int clientSocket);

    int getClientSocket() const;

    void sendMessage(int serverSocket, std::string message) const override;
};


#endif //ECHOAPP_TCPSERVERCLIENT_H
