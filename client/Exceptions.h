#include <utility>

//
// Created by jorgen on 16.10.18.
//

#ifndef ECHOAPP_CLIENT_EXCEPTIONS_H
#define ECHOAPP_CLIENT_EXCEPTIONS_H

#include <string>

class ClientException {
    std::string message;

public:
    explicit ClientException(std::string message) : message(std::move(message)) {

    }

    const std::string &getMessage() const {
        return this->message;
    }
};

class ClientInitializationException : public ClientException {
public:
    ClientInitializationException(const std::string &message)
        : ClientException(message) {}
};

class ClientConnectionException : public ClientException {
public:
    ClientConnectionException(const std::string &message)
            : ClientException(message) {}
};


#endif //ECHOAPP_CLIENT_EXCEPTIONS_H
