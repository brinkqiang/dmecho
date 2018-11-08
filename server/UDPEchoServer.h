//
// Created by jorgen on 16.10.18.
//

#ifndef ECHOAPP_UDPECHOSERVER_H
#define ECHOAPP_UDPECHOSERVER_H


#include "AbstractServer.h"

class UDPEchoServer : public AbstractServer {
public:
    explicit UDPEchoServer(short port);

    void start() override;

protected:
    int createServerSocket() override;
};


#endif //ECHOAPP_UDPECHOSERVER_H
