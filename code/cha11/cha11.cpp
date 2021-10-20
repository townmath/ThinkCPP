#include <iostream>
#include <vector>
#include <cstdlib>
//using namespace std;
using std::endl;
using std::cout;
using std::vector;

int main(){
    vector<int> count (4, 0);
    count[0] = 7;
    count[1] = count[0] * 2;
    count[2]++;
    count[3] -= 60;
    int i = 0;
    while (i < 4) {
        cout << count[i] << endl;
        i++;
    }
    vector<int> copy1 (count);
    //a for loop is sometimes called a fancy while loop
    for (int i = 0; i < 4; i++) {
        cout << copy1[i] << endl;
    }
    vector<int> copy2 = count;
    for (i = 0; i < copy2.size(); i++) {
        cout << copy2[i] << endl;
    }
    srand(time(NULL));
    int upperBound=10;
    int x = rand();
    int y = x % upperBound;
    cout<<x<<" "<<y<<endl;
    int v = rand();
    double w = double(v) / RAND_MAX;
    cout<<v<<" "<<w<<endl;
}
