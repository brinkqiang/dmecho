
#ifndef ECHOAPP_ABSTRACTSERVERTASK_H
#define ECHOAPP_ABSTRACTSERVERTASK_H

#include "AbstractServerClient.h"


class ServerTaskInterface {
public:
    virtual void processClientMessage(const AbstractServerClient &client, std::string message) = 0;
};


#endif //ECHOAPP_ABSTRACTSERVERTASK_H
