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

    Socket::Ptr lSocket( new Socket );
    lSocket->connect( lAddr );

    return lSocket;
}

Socket::Socket( ): iSocketDesc( 0 )
{
    iSocketDesc = ::socket( AF_INET , SOCK_STREAM , 0 );
    assert( iSocketDesc > 0 );
}

Socket::~Socket()
{
    if( !iSocketDesc )
    {
        close( iSocketDesc );
    }
}

void Socket::connect( sockaddr_in & aAddr )
{
    int lRes;

    lRes = ::connect( iSocketDesc , ( struct sockaddr * )&aAddr , sizeof( aAddr ) );
    assert( lRes == 0 );
}

} // MyFramework
