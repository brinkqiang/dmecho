
#ifndef ECHOAPP_ECHOTASK_H
#define ECHOAPP_ECHOTASK_H

#include "ServerTaskInterface.h"


class EchoTask : public ServerTaskInterface {
    int serverSocket;

public:
    explicit EchoTask(int serverSocket);

    void processClientMessage(const AbstractServerClient &client, std::string message) override;
};


#endif //ECHOAPP_ECHOTASK_H
