//
// Created by jorgen on 16.10.18.
//

#include "Exceptions.h"
#include "../../client/src/Exceptions.h"

ServerException::ServerException(std::string message)
        : message(std::move(message)) {

}

const std::string &ServerException::getMessage() const {
    return message;
}

ServerInitializationException::ServerInitializationException(const std::string &message)
        : ServerException(message) {}

ServerPortBusy::ServerPortBusy(short port)
        : ServerException("Port " + std::to_string(port) + " is busy") {

}
