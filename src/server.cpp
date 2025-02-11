#include "server.h"

void Server::start(){
    std::cout << "Server started" << std::endl;
}

void Server::handleClient( int client_socket){
    std::cout << "Your output" << std::endl;
}

Server::Server( int port) : port( port){
    std::cout << "Server initialized on port " << port << std::endl;
}

Server::~Server(){
    std::cout << "engine start, engine go ttrtrtr, engine kaput" << std::endl;
}