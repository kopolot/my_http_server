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
        int clientSocket = this->acceptClient();
        std::string request = this->reciveRequest( clientSocket);
        // placehloder
        std::string response = this->generateResponse( request);
        this->sendResponse( clientSocket ,response);
        this->closeClientSocket( clientSocket);
        std::cout << "Data Recived: \n" <<  std::endl << request << std::endl;
    }
}

std::string Server::generateResponse( std::string request){
    std::string response = 
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/plain\r\n"
    "\r\n"
    "HWDP";
    return response;
}

void Server::sendResponse( int clientSocket, std::string response){
    if( -1 == send( clientSocket, response.c_str(), response.size(), 0))
        perror( "send");
}

void Server::closeClientSocket( int clientSocket){
    close( clientSocket);
}

int Server::acceptClient( ){
    int clientSocket = accept( this->server_fd, nullptr, nullptr);
    if( -1 == clientSocket){
        perror( "accept");
        return -1;
    }
    return clientSocket;
}

std::string Server::reciveRequest( int clientSocket){
    int sizeOffBuffer = 1024;
    char buffer[ sizeOffBuffer] = {0};
    // char buffer[8] = {0};
    std::string request;    
    int bytesReaden = 0;
    do{
        bytesReaden = recv( clientSocket, buffer, sizeof( buffer), 0);
        // std::cout << buffer << std::endl << bytesReaden;
        request += buffer;
    }while( sizeOffBuffer == bytesReaden);
        
    return request;
}

sockaddr_in Server::getServerAddress(){
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons( this->port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    return serverAddress;
}