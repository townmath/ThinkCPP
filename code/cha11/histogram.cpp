#include <iostream>
#include <vector>
using namespace std;

vector<int> randomVector (int n) {
  vector<int> vec (n);
  for (int i = 0; i<vec.size(); i++) {
    vec[i] = random () % 10;
  }
  return vec;
}

void printVector (vector<int> vec) {
  for (int i = 0; i<vec.size(); i++) {
    cout << vec[i];
  }
}

int howMany (vector<int> vec, int value) {
  int count = 0;
  for (int i=0; i< vec.size(); i++) {
    if (vec[i] == value) count++;
  }
  return count;
}

int main ()
{
  int numValues = 100000;

  srandom (17);
  vector<int> randVector = randomVector (numValues);
  vector<int> histogram (10, 0);

  for (int i = 0; i<numValues; i++) {
    int index = randVector[i];
    histogram[index]++;
  }

  for (int i = 0; i<10; i++) {
    cout << i << "\t" << histogram[i] << endl;
  }
  return 0;
}
