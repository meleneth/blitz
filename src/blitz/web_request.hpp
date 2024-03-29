#ifndef WEBREQUEST_HPP
#define WEBREQUEST_HPP

#include "blitz_types.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Blitz {
class WebRequest {
    public:
        WebRequest(TCPConnection_ptr client);
        WebRequest(string uri);
        ~WebRequest();

        void parse_uri(string uri);
        void parse_headers(void);
        void split_request_uri(string uri);
        void defaults(void);
        string get_uri(void);
        string param(string name);
        unsigned int paramn(string name);
        unsigned int param_index(string name);
        void delete_param(string name);
        void param(string name, string value);
        void param(string name, unsigned int value);
        bool has_param(string name);

        TCPConnection_ptr client;
        string request_string;
        string path;
        string filename;
        string content_type;
        unsigned int http_minor_version;
        unsigned int http_major_version;
        unsigned int has_cgi_params;


        vector<string> param_names;
        vector<string> param_values;

        string response_text;
        string response_headers;
        int sent_bytes;

    private:
    protected:
};

}

#endif
