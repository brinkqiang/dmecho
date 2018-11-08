//
// Created by jorgen on 16.10.18.
//

#ifndef ECHOAPP_ABSTRACTCLIENT_H
#define ECHOAPP_ABSTRACTCLIENT_H

#include <Sockets.h>

class AbstractClient {
protected:
    int clientSocket;
    sockaddr_in serverAddress;
    std::string serverAddressString;

public:
    explicit AbstractClient(std::string serverAddress, short port);
    ~AbstractClient();

    void initialize();

    virtual void sendMessage(std::string message) = 0;
    virtual std::string receiveMessage() = 0;

private:
    virtual void connect() = 0;

    virtual int createClientSocket() = 0;
};


#endif //ECHOAPP_ABSTRACTCLIENT_H
