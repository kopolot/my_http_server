#include <iostream>
#include "server.h"
#include <signal.h>

Server* app;

void signal_interrupt( int signum){
    delete app;
    std::cout << "HWPDP\n";
    exit( signum);
}

int main(){
    app = new Server( 8080);
    signal( SIGINT, signal_interrupt);
    (*app).start();
    delete app;
    return 0;
}