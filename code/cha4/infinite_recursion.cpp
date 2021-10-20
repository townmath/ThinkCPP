#include <iostream>
using std::cout;
using std::endl;

void newLine () {
  cout << endl;
}

void threeLine () {
  newLine ();  newLine ();  newLine ();
}

void nLines (int n) {
  if (1) {//warning infinite recursion, how to fix?
    cout << endl;
    nLines (n-1);
  }
}
int main () {
  cout << "First Line." << endl;
  nLines (3);
  cout << "Second Line." << endl;
  return 0;
}
