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

void Socket::write( const char * aSrc, size_t aLen )
{
    int lRes;

    lRes = ::send( iSocketDesc, aSrc , aLen, 0 ) ;
    // unsupported partial send
    assert( lRes != -1 and lRes == static_cast<int>( aLen ) );
}

void Socket::read( char * aDst, size_t aLen )
{
    int lRes;

    lRes = recv( iSocketDesc, aDst, aLen , 0 );
    // unsupported partial recv
    assert( lRes != -1 and lRes == static_cast<int>( aLen ) );

}

} // MyFramework
