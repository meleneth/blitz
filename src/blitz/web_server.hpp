#ifndef WEBSERVER_HPP
#define WEBSERVER_HPP

#include "blitz_types.hpp"

#include <string>
#include <list>

// This entire webserver is such a non-standard-using
// non RFC piece of work, that this program shouldn't
// even be using it.

namespace Blitz {

class WebServer {
    public:
        WebServer(std::string document_root, int port_no);
        ~WebServer();

        void log_to_file(std::string filename);
        void handle_request(WebRequest *request);
        void handle_new_connection(void);
        void register_file(std::string url, std::string filename, std::string content_type);
        void tick(void);

        std::shared_ptr<TCPListener> listener;
        TCPConnection_list connections;
        WebDataFetcher_list handlers;
        std::string web_root;
        
        WebStaticFile_list static_contents;

    private:
    protected:
};

}

#endif
