#ifndef console_inc
#define console_inc 1

#include "blitz_types.hpp"

#include<fstream>
#include<sstream>

namespace Blitz {

  class Console {
    public:
      // Public data members go here.
      Console(); // Constructor
      ~Console(); // Destructor

      void log(std::string line);
      void log(int number);
      void log(double number);
      void log(long number);
      void fatal(std::string line);
      void box_log(std::string line);
      void open_log_file(void);

      String_list loglines;

      std::stringstream partial_line;
      bool has_partial_characters;

      template <typename T>
        Console &operator<<(const T &a) {
          partial_line << a;
          has_partial_characters = true;
          return *this;
        }

      Console &operator<<(std::ostream& (*pf) (std::ostream&)){
        has_partial_characters = false;
        log(partial_line.str());
        partial_line.str("");
        return *this;
      }

      std::string input;
      bool print_logs;
      bool print_on_delete;
      bool keep_logs;
      bool save_to_file;
      std::ofstream out;

    private:
      // Private members go here.
    protected:
      // Protected members go here.
  };

  extern Console console;

}

#endif
