
#include <iostream>

#include "Socket.hpp"

int main( int argc, char const * argv[] )
{
    std::cout << "aaa" << std::endl;

    std::string lHost = "127.0.0.1";

    MyFramework::Socket::Ptr lSocketPtr = MyFramework::Socket::createSocket( lHost, 12345 );
    const char * lAaaa = "hejka\n";
    size_t lSize = sizeof( lAaaa );
    lSocketPtr->write( lAaaa, lSize );


    return 0;
}