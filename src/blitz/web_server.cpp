#include "blitz_types.hpp"

#include "web_server.hpp"
#include "web_request.hpp"
#include "web_response.hpp"
#include "console.hpp"
#include "webdatafetcher.hpp"
#include "tcplistener.hpp"
#include "tcpconnection.hpp"
#include "web_static_file.hpp"

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

#include<sstream>

using namespace Blitz;
using namespace std;

WebServer::WebServer(std::string web_root, int port_no)
{
  listener = make_shared<TCPListener>(port_no);
  this->web_root = web_root;
}

WebServer::~WebServer()
{
  listener = nullptr;
  static_contents.empty();
}

namespace Blitz {
  extern void handle_web_request(WebRequest *request, WebResponse *response);
}

void WebServer::handle_request(WebRequest *request)
{
  WebResponse response;

  console.log(request->get_uri());
  
  if(request->path == "/") {
    for(auto sc : static_contents) {
      if (sc->filename == request->filename) {
        response.content_type = sc->content_type;
        response.prepare_response_for_bytes(sc->content_length);
        request->client->send_data((char *)response.full_response.c_str(), response.full_response.length());
        request->client->send_data(sc->buffer, sc->content_length);
        return;
      }
    }
  }

  //handle_web_request(request, &response);
  response.prepare_full_response();

  request->client->send_data((char *) response.full_response.c_str(), response.full_response.length());
}

void WebServer::tick(void)
{
    for(auto i = connections.begin(); i != connections.end(); ++i) {
        if((*i)->has_data_waiting()){
            WebRequest *r = new WebRequest(*i);
            handle_request(r);
            delete r;
            list <TCPConnection_ptr>::iterator p = i;
            --i;
            connections.erase(p);
        }
    }

    list<WebDataFetcher_ptr>::iterator h;

    for(h = handlers.begin(); h != handlers.end() ; ++h) {
        if (!(*h)->tick()) {
            list<WebDataFetcher_ptr>::iterator j = h;
            WebDataFetcher_ptr r = (*h);
            --h;
            handlers.erase(j);
        }
    }
}

void WebServer::log_to_file(string filename)
{
}

void WebServer::handle_new_connection(void)
{
    connections.push_back(listener->get_waiting_connection());
}

void WebServer::register_file(string url, string filename, std::string content_type)
{
  auto static_file = make_shared<WebStaticFile>();

  struct stat file_stats;
  stat(filename.c_str(), &file_stats);

  int num_bytes = file_stats.st_size;
  char *buffer = (char *)malloc(num_bytes);

  static_file->content_length = num_bytes;
  static_file->buffer = buffer;
  static_file->filename = url;

  static_contents.push_back(static_file);

  FILE *fp = fopen(filename.c_str(), "r");
  fread(buffer, num_bytes, 1, fp);
  fclose(fp);
}

