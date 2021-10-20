#include <iostream>
using std::cout;
using std::endl;
// main: generate some simple output

int main ()
{
  cout << "Hello, world." << endl;     // output one line
  cout << "How are you?" << endl;      // output another

  int hour, minute;
  char colon;
  hour = 11;
  minute = 59;
  colon = ':';
  cout << "The current time is ";
  cout << hour;
  cout << colon;
  cout << minute;
  cout << endl;

  char letter;
  letter = 'a' + 1;
  cout << letter << endl;

  int number;
  number = 'a';
  cout << number << endl;
  return 0;
}
