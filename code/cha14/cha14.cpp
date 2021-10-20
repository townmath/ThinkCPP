#include <iostream>
using std::cout;
using std::endl;

int perform_addition(int a, int b);
int perform_multiplication(int a, int b);

int main(){
    int a=5, b=3;
    char symbol='+';
    switch (symbol) {
    case '+':
      cout << a << " + " << b << " = "<< perform_addition (a,b) << endl;
      break;
    case '*':
      cout << a << " * " << b << " = "<<perform_multiplication (a,b) << endl;
      break;
    default:
      cout << "I only know how to perform addition and multiplication" << endl;
      break;
    }
}

int perform_addition(int a, int b){
    return a+b;
}
int perform_multiplication(int a, int b){
    return a*b;
}
