#include <iostream>
#include <memory>

#include "AbstractClient.h"
#include "UDPClient.h"
#include "TCPClient.h"
#include "Exceptions.h"

void printUsage(const char *appName) {
    std::cout << "Echo client" << std::endl;
    std::cout << "Usage: " << appName << " (udp|tcp) ip port" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printUsage(argv[0]);
        exit(1);
    }


    std::string ip = argv[2];
    short port = static_cast<short>(std::stoi(argv[3]));

    std::unique_ptr<AbstractClient> client;

    if (std::string(argv[1]) == "udp") {
        client = std::make_unique<UDPClient>(ip, port);
    } else if (std::string(argv[1]) == "tcp") {
        client = std::make_unique<TCPClient>(ip, port);
    } else {
        printUsage(argv[0]);
        exit(1);
    }

    try {
        client->initialize();
    } catch (const ClientException &e) {
        std::cerr << "Failed to connect to init client: " + e.getMessage() << std::endl;
        exit(1);
    }

    std::cout << "Connected to " << ip << std::endl;

    std::string input;
    while (true) {
        std::cout << "Message: ";
        getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        try {
            client->sendMessage(input);
            std::string answer = client->receiveMessage();

            std::cout << "Server: " << answer << std::endl;
        } catch(const ClientException &e) {
            std::cerr << e.getMessage() << std::endl;
            break;
        }
    }

    std::cout << "Terminating client" << std::endl;
}