#include <iostream>
#include <thread>
#include "TCPEchoServer.h"
#include "UDPEchoServer.h"
#include "NumberTask.h"

void printUsage(const char *appName) {
    std::cout << "Usage: " << appName << " tcpPort udpPort" << std::endl;
}

void startTCPServer(short port) {
    try {
        std::cout << "Initialize the TCP server on " << port << " port" << std::endl;

        TCPEchoServer tcpServer(port);
        tcpServer.initialize();

        // Add numbers task
        tcpServer.addServerTask(std::make_shared<NumberTask>());

        std::cout << "Starting the TCP server on " << port << "..." << std::endl;
        tcpServer.start();
        std::cout << "TCP Server started on " << port << " port" << std::endl;
    } catch (const ServerInitializationException &e) {
        std::cerr << "Failed to init TCP server: " << e.getMessage() << std::endl;
    } catch (const ServerException &e) {
        std::cerr << "Server error: " << e.getMessage() << std::endl;
    }
}

void startUDPServer(short port) {
    try {
        std::cout << "Initialize the UDP server on " << port << " port" << std::endl;

        UDPEchoServer udpServer(port);
        udpServer.initialize();

        // Add numbers task
        udpServer.addServerTask(std::make_shared<NumberTask>());

        std::cout << "Starting the UDP server on " << port << "..." << std::endl;
        udpServer.start();
        std::cout << "UDP Server started on " << port << " port" << std::endl;
    } catch (const ServerInitializationException &e) {
        std::cerr << "Failed to init UDP server: " << e.getMessage() << std::endl;
    } catch (const ServerException &e) {
        std::cerr << "Server error: " << e.getMessage() << std::endl;
    }
}

int main(int argc, char **argv) {
    std::cout << "EchoServer (UDP, TCP) v1.0" << std::endl;

    if (argc < 3) {
        printUsage(argv[0]);
        exit(1);
    }

    short tcpPort = static_cast<short>(std::stoi(argv[1]));
    short udpPort = static_cast<short>(std::stoi(argv[2]));

    std::thread tcpServerThread([tcpPort](){
        startTCPServer(tcpPort);
    });

    std::thread udpServerThread([udpPort](){
        startUDPServer(udpPort);
    });

    tcpServerThread.join();
    std::cout << "TCP Server terminated" << std::endl;

    udpServerThread.join();
    std::cout << "UDP Server terminated" << std::endl;

    return 0;
}
