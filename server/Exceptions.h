//
// Created by jorgen on 16.10.18.
//

#ifndef ECHOAPP_EXCEPTIONS_H
#define ECHOAPP_EXCEPTIONS_H

#include <string>
#include <exception>

class ServerException {
    std::string message;

public:
    explicit ServerException(std::string message);

    const std::string &getMessage() const;
};

class ServerInitializationException : public ServerException {
public:
    explicit ServerInitializationException(const std::string &message);
};

class ServerPortBusy : public ServerException {
public:
    ServerPortBusy(short port);
};


#endif //ECHOAPP_EXCEPTIONS_H
