#include<iostream>
#include <cmath>
using namespace std;

int main () {
	int num1, rem , dec, i;
    cin >> num1;
    dec = 0 ;
    i = 0;
    while(num1 != 0){
        rem = num1 %  10;
        num1 /= 10;
        dec += rem * pow(2,i);
        ++i;
  
    }  
    cout << dec << endl;  

}