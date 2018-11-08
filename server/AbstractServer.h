
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

    
    void initialize();

    
    virtual void start() = 0;

    
    void addServerTask(std::shared_ptr<ServerTaskInterface> task);

protected:

    
    virtual int createServerSocket() = 0;

    
    void processClientMessage(const AbstractServerClient &client, std::string message);
private:
    
    void bind();
};


#endif //ECHOAPP_ABSTRACTSERVER_H
