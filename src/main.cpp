#include <iostream>
#include "server.h"

int main(){
    // std::cout << "Działa plik" << std::endl;
    Server app( 8080);
    app.start();
    return 0;
}