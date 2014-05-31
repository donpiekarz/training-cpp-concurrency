#include "Socket.hpp"


namespace MyFramework
{

Socket::Ptr Socket::createSocket( std::string aHost, int aPort )
{

    sockaddr_in lAddr;
    lAddr.sin_addr.s_addr = inet_addr( aHost.c_str() );
    lAddr.sin_family = AF_INET;
    lAddr.sin_port = htons( aPort );

    Socket::Ptr lSocket( new Socket( lAddr ) );

    return lSocket;
}

Socket::Socket( sockaddr_in & aAddr )
{
    std::cout << aAddr.sin_port << std::endl;
}

Socket::~Socket()
{

}

} // MyFramework
