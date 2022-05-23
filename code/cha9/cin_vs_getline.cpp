#include <iostream>
using namespace std;

int main ()
{
  string name;

  cout << "What is your name? ";
  cin >> name;
  cout << name << endl;

  cin.ignore();
  cout << "What is your name? ";
  getline (cin, name);
  cout << name << endl;

  return 0;
}

