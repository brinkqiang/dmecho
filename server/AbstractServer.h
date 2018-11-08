//
// Created by jorgen on 16.10.18.
//

#ifndef ECHOAPP_ABSTRACTSERVER_H
#define ECHOAPP_ABSTRACTSERVER_H

#include <Sockets.h>
#include <list>
#include <memory>

#include "Exceptions.h"
#include "AbstractServerClient.h"
#include "ServerTaskInterface.h"

class AbstractServer {
protected:
    int serverSocket;
    short port;

    std::list<std::shared_ptr<ServerTaskInterface>> tasks;
public:
    explicit AbstractServer(short port);

    /**
     * Initialize a server. Creates the server socket and binds it.
     *
     * @throws ServerInitializationException
     */
    void initialize();

    /**
     * Start a server loop.
     *
     * @throws ServerException
     */
    virtual void start() = 0;

    /**
     * Add the task to the server.
     *
     * @param task Server task pointer
     */
    void addServerTask(std::shared_ptr<ServerTaskInterface> task);

protected:

    /**
     * Create server socket and return integer socket descriptor
     *
     * @return Socket descriptor
     */
    virtual int createServerSocket() = 0;

    /**
     * Process a message from a client.
     *
     * @param client    Server client
     * @param message   Message string
     */
    void processClientMessage(const AbstractServerClient &client, std::string message);
private:
    /**
     * Bind the server socket to all interfaces on the specified port
     *
     * @throws ServerInitializationException If failed to bind the socket
     */
    void bind();
};


#endif //ECHOAPP_ABSTRACTSERVER_H
