//
// Created by jorgen on 16.10.18.
//

#ifndef ECHOAPP_ECHOTASK_H
#define ECHOAPP_ECHOTASK_H

#include "ServerTaskInterface.h"

/**
 * Echo message back to the client
 */
class EchoTask : public ServerTaskInterface {
    int serverSocket;

public:
    explicit EchoTask(int serverSocket);

    void processClientMessage(const AbstractServerClient &client, std::string message) override;
};


#endif //ECHOAPP_ECHOTASK_H
