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
        int handleClient();
        sockaddr_in getServerAddress();

};

#endif