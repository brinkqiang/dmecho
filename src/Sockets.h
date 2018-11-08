//
// Created by jorgen on 15.10.18.
//

#ifndef ECHOAPP_SOCKETS_H
#define ECHOAPP_SOCKETS_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>

/**
 * Helper sockets class
 */
class Sockets {
public:
    static std::string getAddressString(sockaddr *address);
    static std::string getAddressString(sockaddr_in *address);
    static std::string getAddressString(sockaddr_in6 *address);

    static sockaddr_in parseIPv4Address(std::string addressString);

    static size_t getMaxBufferLength();
};

#endif //ECHOAPP_SOCKETS_H
