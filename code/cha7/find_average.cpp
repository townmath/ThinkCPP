#include <iostream>
using std::cout;

double find_the_average(int numArr[], int size){
    double average=0;
    for(int i=0; i<size; i++){
        average+=numArr[i];
    }
    average/=size;
    return average;
}

int main() {
    int num1=5;
    int num2=7;
    int num3=10;
    double average;
    average=(num1+num2+num3)/3.0;
    cout<<"The average is "<<average<<endl;

    int numArr[]={5,6,10,6,3,12,7,8,3,11};
    int size=10;
    double average;
    average=find_the_average(numArr,size);
    cout<<"The average is "<<average<<endl;
}
