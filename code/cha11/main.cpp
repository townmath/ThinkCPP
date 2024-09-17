#include <iostream>
using std::cout;
using std::endl;
#include "time.h" //don't forget to include this
//here is main where you can use everything from the other files
int main ()
{
  Time currentTime = { 9, 14, 30.0 };
  increment (currentTime, 500.0);
  printTime (currentTime);

  Time breadTime = { 3, 35, 0.0 };
  Time doneTime = addTime (currentTime, breadTime);
  printTime (doneTime);

  if (after (doneTime, currentTime)) {
    cout << "The bread will be done after it starts." << endl;
  }
  return 0;
}
