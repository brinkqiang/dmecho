//
// Created by jorgen on 16.10.18.
//

#ifndef ECHOAPP_UDPCLIENT_H
#define ECHOAPP_UDPCLIENT_H

#include "AbstractClient.h"

class UDPClient : public AbstractClient {
public:
    UDPClient(const std::string &serverAddress, short port);

    void sendMessage(std::string message) override;

    std::string receiveMessage() override;

private:
    void connect() override;

    int createClientSocket() override;
};


#endif //ECHOAPP_UDPCLIENT_H
