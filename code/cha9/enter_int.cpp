#include <iostream>
using namespace std;

int main () {
    int x;
    
    // prompt the user for input
    cout << "Enter an integer: ";
    
    // get input
    cin >> x;
    
    // check and see if the input statement succeeded
    if (cin.good() == false) {
        cout << "That was not an integer." << endl;
        return -1;
    }
    
    // (implied else) print the value we got from the user
    cout << "You entered: " << x << endl;
    return 0;
}
