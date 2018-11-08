//
// Created by jorgen on 16.10.18.
//

#ifndef ECHOAPP_UDPSERVERCLIENT_H
#define ECHOAPP_UDPSERVERCLIENT_H


#include "AbstractServerClient.h"

class UDPServerClient : public AbstractServerClient {
public:
    UDPServerClient(sockaddr *address);

    void sendMessage(int serverSocket, std::string message) const override;
};


#endif //ECHOAPP_UDPSERVERCLIENT_H
