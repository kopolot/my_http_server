#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class Server{
    public:
        Server( int port);
        ~Server();
        void start();
    protected:
        int server_fd;
        int port;
        int acceptClient();
        sockaddr_in getServerAddress();
        std::string reciveRequest( int clientSocket);
        void closeClientSocket( int clientSocket);
        std::string generateResponse( std::string request);
        void sendResponse( int clientSocket ,std::string response);
};

#endif