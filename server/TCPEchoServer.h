//
// Created by jorgen on 15.10.18.
//

#ifndef ECHOAPP_TCPECHOSERVER_H
#define ECHOAPP_TCPECHOSERVER_H

#include <Sockets.h>
#include "Exceptions.h"
#include "AbstractServer.h"

#include <string>

/**
 * Single thread. Blocking echo server.
 */
class TCPEchoServer : public AbstractServer {

public:
    explicit TCPEchoServer(short port);

    /**
     * Start listening for incoming connections
     */
    void start() override;


protected:
    int createServerSocket() override;

private:
    void processClient(int clientSocket, sockaddr *clientAddress);
};


#endif //ECHOAPP_TCPECHOSERVER_H
