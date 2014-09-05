#include <iostream>
#include "console.hpp"

using namespace std;
using namespace Blitz;

Console Blitz::console;

int main(int argc, char *argv[])
{
  cout << "blitz: blitz\n";
  console.print_logs = 1;

  console << "RA" << endl;
  return 0;
}



