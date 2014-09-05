#ifndef WEBSTATICFILE_HPP
#define WEBSTATICFILE_HPP

#include "blitz_types.hpp"

namespace Blitz {

class WebStaticFile {
  public:
    WebStaticFile();
    ~WebStaticFile();

    std::string url;
    std::string filename;
    std::string content_type;
    char *buffer;
    int content_length;
};

}

#endif
