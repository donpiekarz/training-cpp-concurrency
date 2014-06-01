#include "Socket.hpp"

#include <cassert>
#include <cerrno>
#include <cstring>

namespace MyFramework
{

Socket::Ptr Socket::createSocket( std::string & aHost, uint16_t aPort )
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
    int lRes;

    iSocketDesc = socket( AF_INET , SOCK_STREAM , 0 );
    assert( iSocketDesc > 0 );

    lRes = connect( iSocketDesc , ( struct sockaddr * )&aAddr , sizeof( aAddr ) );
    assert( lRes == 0 );
}

Socket::~Socket()
{
    close( iSocketDesc );
}

} // MyFramework
