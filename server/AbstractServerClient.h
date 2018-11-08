
#ifndef ECHOAPP_SERVERCLIENT_H
#define ECHOAPP_SERVERCLIENT_H

#include <Sockets.h>


class AbstractServerClient {
protected:
    sockaddr *address;
    std::string addressString;

public:
    explicit AbstractServerClient(sockaddr *address);

    const std::string &getAddressString() const;

    sockaddr *getAddress() const;

    
    virtual void sendMessage(int serverSocket, std::string message) const = 0;
};


#endif //ECHOAPP_SERVERCLIENT_H
