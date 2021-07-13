#include<iostream>
using namespace std;

void countdownOdd(int n){
    if(n == 0){
        return; 
    }
    if(n % 2 != 0)
        cout << n << endl;
    
    return countdownOdd(n-1);
}

void countUpEven(int n){
    if(n > 0){
        countUpEven(n - 1);
        if(n % 2 == 0){
            cout << n << endl;

        }
    }
    
}
int main(){
    int num;
    cin >> num;
    countdownOdd(num - 1);
    countUpEven(num);
}