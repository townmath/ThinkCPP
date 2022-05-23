#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

void countdown (int n) {
  while (n > 0) {
    cout << n << endl;
    n = n-1;
  }
  cout << "Blastoff!" << endl;
}


void printMultiples (int n, int high) {
  int i = 1;
  while (i <= high) {
    cout << n*i << "   ";
    i = i + 1;
  }
  cout << endl;
}

void printMultTable (int high) {
  int i = 1;
  while (i <= high) {
    printMultiples (i, i);
    i = i + 1;
  }
}

int main ()
{
  countdown(3);

  printMultTable (7);

  return 0;
}
