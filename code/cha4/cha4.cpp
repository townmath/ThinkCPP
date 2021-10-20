#include <iostream>
#include <cmath>
using namespace std;
void printLogarithm (double x) {
  if (x <= 0.0) {
    cout << "Positive numbers only, please." << endl;
    return;
}
  double result = log (x);
  cout << "The log of "<< x << " is " << result << endl;
}

void countdown (int n) {
  if (n == 0) {
    cout << "Blastoff!" << endl;
  } else {
    cout << n << endl;
    countdown (n-1);
  }
}
int main () {
    printLogarithm(-1);
    printLogarithm(2);
    countdown (3);
    return 0;
}
