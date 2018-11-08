//
// Created by jorgen on 15.10.18.
//

#include "Sockets.h"

std::string Sockets::getAddressString(sockaddr *address) {
    if (address->sa_family == AF_INET) {
        return getAddressString(reinterpret_cast<sockaddr_in*>(address));
    } else if (address->sa_family == AF_INET6) {
        return getAddressString(reinterpret_cast<sockaddr_in6*>(address));
    }

    return "Unknown protocol address";
}

std::string Sockets::getAddressString(sockaddr_in *address) {
    char addressString[INET6_ADDRSTRLEN];

    int port = ntohs(address->sin_port);
    inet_ntop(AF_INET, &address->sin_addr, addressString, sizeof(addressString));

    return addressString;
}

std::string Sockets::getAddressString(sockaddr_in6 *address) {
    char addressString[INET6_ADDRSTRLEN];

    int port = ntohs(address->sin6_port);
    inet_ntop(AF_INET6, &address->sin6_addr, addressString, sizeof(addressString));

    return std::string(addressString);
}

sockaddr_in Sockets::parseIPv4Address(std::string addressString) {
    sockaddr_in address {};
    inet_pton(AF_INET, addressString.data(), &(address.sin_addr));

    return address;
}

size_t Sockets::getMaxBufferLength() {
    return 1024 * 64;
}

