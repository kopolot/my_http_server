#include "server.h"
// #include <fmt/core.h>

void handle_error( char *msg){
    perror( msg);
    exit( EXIT_FAILURE);
}

Server::Server( int port) : port( port){
    this->port = port;
    this->server_fd = socket( AF_INET, SOCK_STREAM, 0);
    if( -1 == this->server_fd)
        handle_error( (char*)"socket");
    sockaddr_in serverAddress = this->getServerAddress();
    if( -1 == bind( this->server_fd, ( struct sockaddr*)&serverAddress, sizeof( serverAddress)))
        handle_error( (char *)"bind");
    std::cout << "Server initialized on port " << port << std::endl;
}

Server::~Server(){
    close( this->server_fd);
    std::cout << "engine start, engine go ttrtrtr, engine kaput" << std::endl;
}

void Server::start(){
    listen( this->server_fd, 5);
    std::cout << "Server started" << std::endl;
    while ( true){
        this->handleClient();
    }
}

int Server::handleClient( ){
    int clientSocket = accept( this->server_fd, nullptr, nullptr);
    if( -1 == clientSocket){
        perror( "accept");
        return EXIT_FAILURE;
    }

    std::cout << "Data Recived: \n" <<  std::endl;
    char buffer[1024] = {0};
    // char buffer[8] = {0};
    while ( sizeof( buffer) == recv( clientSocket, buffer, sizeof( buffer), 0))
        std::cout << buffer;
    close( clientSocket);
    return EXIT_SUCCESS;
}

sockaddr_in Server::getServerAddress(){
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons( this->port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    return serverAddress;
}