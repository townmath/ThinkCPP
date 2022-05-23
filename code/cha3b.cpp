#include <iostream>
using namespace std;

//function prototype
void newLines(int); //parameter name optional

int main () {
  cout << "First Line." << endl;
  newLines(3);
  cout << "Second Line." << endl;
  return 0;
}

//function definition
void newLines(int numLines) {
  for (int i=0; i<numLines; i++){
    cout << endl;
  }
}
