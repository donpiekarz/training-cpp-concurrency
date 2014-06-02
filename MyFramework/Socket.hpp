#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <cstdint>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

namespace MyFramework
{


class Socket
{
public:
    typedef int Desc;
    typedef std::shared_ptr<Socket> Ptr;

    static Ptr createSocket( std::string &, uint16_t );
    ~Socket();

    void connect( sockaddr_in & aAddr );

    void write( const char *, size_t );
    void read( char *, size_t );

private:

    Socket();

    Desc getDescriptor();

    Desc iSocketDesc;

};


} // MyFramework