
#ifndef ECHOAPP_TCPECHOSERVER_H
#define ECHOAPP_TCPECHOSERVER_H

#include <Sockets.h>
#include "Exceptions.h"
#include "AbstractServer.h"

#include <string>


class TCPEchoServer : public AbstractServer {

public:
    explicit TCPEchoServer(short port);

    
    void start() override;


protected:
    int createServerSocket() override;

private:
    void processClient(int clientSocket, sockaddr *clientAddress);
};


#endif //ECHOAPP_TCPECHOSERVER_H
