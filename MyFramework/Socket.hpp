#pragma once

#include <sys/socket.h>

namespace MyFramework {

class Socket
{
public:
    typedef int Desc;
    Socket(){}
    ~Socket(){}

    void read();
    void write();

    const Desc getDescriptor();
    
};


} // MyFramework