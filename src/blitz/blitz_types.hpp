#ifndef BLITZTYPES_HPP
#define BLITZTYPES_HPP

#include <memory>
#include <list>

namespace Blitz {

  class WebServer;
  class WebRequest;
  class StringPattern;
  class TCPConnection;
  class TCPListener;
  class WebDataFetcher;
  class WebRequest;
  class WebResponse;
  class WebServer;
  class WebStaticFile;

  typedef std::shared_ptr<TCPConnection> TCPConnection_ptr;
  typedef std::shared_ptr<WebDataFetcher> WebDataFetcher_ptr;

  typedef std::list<std::string> String_list;
  typedef std::list<TCPConnection_ptr> TCPConnection_list;
  typedef std::list<std::shared_ptr<WebDataFetcher>> WebDataFetcher_list;
  typedef std::list<std::shared_ptr<WebStaticFile>> WebStaticFile_list;

};

#endif
