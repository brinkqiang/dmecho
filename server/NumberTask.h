//
// Created by jorgen on 16.10.18.
//

#ifndef ECHOAPP_NUMBERTASK_H
#define ECHOAPP_NUMBERTASK_H


#include "ServerTaskInterface.h"
#include <list>

/**
 * Find all numbers from 0 to 9 in message and
 *  1. Sum of all numbers
 *  2. Prints all numbers in descending order
 *  3. Maximum and minimum values
 */
class NumberTask : public ServerTaskInterface {
    std::list<int> numbers;

public:
    void processClientMessage(const AbstractServerClient &client, std::string message) override;

private:
    void extractNumbers(std::string message);
};


#endif //ECHOAPP_NUMBERTASK_H
