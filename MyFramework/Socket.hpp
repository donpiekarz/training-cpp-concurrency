#pragma once

#include <iostream>
#include <string>
#include <memory>

#include <sys/socket.h>
#include <arpa/inet.h>

namespace MyFramework
{


class Socket
{
public:
    typedef int Desc;
    typedef std::shared_ptr<Socket> Ptr;

    static Ptr createSocket( std::string, int );
    ~Socket();

    void read();
    void write();

private:

    Socket( sockaddr_in & );

    Desc getDescriptor();

};


} // MyFramework