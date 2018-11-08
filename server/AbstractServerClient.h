//
// Created by jorgen on 16.10.18.
//

#ifndef ECHOAPP_SERVERCLIENT_H
#define ECHOAPP_SERVERCLIENT_H

#include <Sockets.h>

/**
 * Client of a server
 */
class AbstractServerClient {
protected:
    sockaddr *address;
    std::string addressString;

public:
    explicit AbstractServerClient(sockaddr *address);

    const std::string &getAddressString() const;

    sockaddr *getAddress() const;

    /**
     * Send a message to the client.
     *
     * @param serverSocket Server socket
     * @param message Message to send to the server
     */
    virtual void sendMessage(int serverSocket, std::string message) const = 0;
};


#endif //ECHOAPP_SERVERCLIENT_H
