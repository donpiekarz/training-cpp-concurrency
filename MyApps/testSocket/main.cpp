
#include <iostream>

#include "Socket.hpp"

int main( int argc, char const * argv[] )
{
    std::cout << "aaa" << std::endl;

    std::string lHost = "localhost";

    MyFramework::Socket::Ptr lSocketPtr = MyFramework::Socket::createSocket( lHost, 1 );


    return 0;
}