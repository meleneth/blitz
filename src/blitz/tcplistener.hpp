#ifndef ___tcplistener_inc
#define ___tcplistener_inc 1

#include "blitz_types.hpp"
#include <netinet/in.h>

namespace Blitz {
class TCPListener {
    public:
        TCPListener(int port_num);
        ~TCPListener();

        TCPConnection_ptr get_waiting_connection();
        int has_connection_waiting();

        int port_no;
        int sockfd;  // listen on sock_fd
        struct sockaddr_in my_addr;    // my address information
        int yes;

    private:
    protected:
};

}

#endif
