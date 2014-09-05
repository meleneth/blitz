#include "console.hpp"

#include<iomanip>
#include<ios>
#include<stdio.h>
#include<iostream>

#include "reverse.hpp"

using namespace Blitz;

using std::string;
using std::stringstream;
using std::list;
using std::setprecision;
using std::ios;
using std::endl;
using std::cout;

#define CONSOLE_MAX_SIZE 1000

// Public data members go here.
Console::Console() // Constructor
{
    print_logs             = 0;
    input                  = "";
    print_on_delete        = 0;
    keep_logs              = 1;
    save_to_file           = 0;
    has_partial_characters = false;

    box_log("Console Initialized");
}

Console::~Console() // Destructor
{
    if(print_on_delete){
        for (auto s : reverse_iterate(loglines)){
          cout << s << endl;
        }
    }
    if(save_to_file){
        out.close();
    }
}

void Console::open_log_file(void)
{
  out.open("console.log", ios::out);
  save_to_file = 1;
}

void Console::log(string line)
{
  if(has_partial_characters) {
    has_partial_characters = false;
    log(partial_line.str());
    partial_line.str("");
  }
  if(keep_logs) {
    loglines.push_back(line);
  }
  if(print_logs){
    cout << line << std::endl;
  }
  if(save_to_file){
      out << line << endl;
  }
}

void Console::log(int number)
{
    stringstream st;
    st << number;
    log(st.str());
}

void Console::log(double number)
{
    stringstream st;
    st << number;
    log(st.str());
}

void Console::log(long number)
{
    stringstream st;
    st << number;
    log(st.str());
}

void Console::fatal(string line)
{
    log(line);
}

void Console::box_log(string line)
{
    string Border(line.length() + 2, '-');

    log("+" + Border + "+");
    log("| " + line + " |");
    log("+" + Border + "+");
}

