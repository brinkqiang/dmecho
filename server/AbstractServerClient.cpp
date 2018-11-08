//
// Created by jorgen on 16.10.18.
//

#include "AbstractServerClient.h"

AbstractServerClient::AbstractServerClient(sockaddr *address)
    : address(address) {
    this->addressString = Sockets::getAddressString(this->address);
}

const std::string &AbstractServerClient::getAddressString() const {
    return addressString;
}

sockaddr *AbstractServerClient::getAddress() const {
    return address;
}
