//
// Created by jorgen on 16.10.18.
//

#ifndef ECHOAPP_TCPCLIENT_H
#define ECHOAPP_TCPCLIENT_H

#include "AbstractClient.h"

class TCPClient : public AbstractClient {
public:
    TCPClient(const std::string &serverAddress, short port);

    void sendMessage(std::string message) override;

    std::string receiveMessage() override;

private:
    void connect() override;

    int createClientSocket() override;
};


#endif //ECHOAPP_TCPCLIENT_H
