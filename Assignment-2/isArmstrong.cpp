#include<iostream>
#include <cstring>
using namespace std;

bool isArmstrong( int num ){
    int tempnum = num;
    int sum = 0 ;

    while(num > 0) {
        int r = num % 10;
        cout << r << endl;
        sum = sum + (r * r * r);
        cout  << sum << endl;
        num  = num /10;
        cout << num << endl;
    }

    if(tempnum == sum ){
        return true;
    }
    else{
        return false;
    }
}
    

int main () {
    int num;
    cin >> num;
   
    isArmstrong(num) ? cout << "true" << endl : cout << "false" << endl;
    
}