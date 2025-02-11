#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class Server{
    public:
        Server( int port);
        ~Server();
        void start();
    private:
        int server_fd;
        int port;
        void handleClient( int client_socket);
};

#endif