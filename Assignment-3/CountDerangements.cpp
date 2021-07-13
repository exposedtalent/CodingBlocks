#include<iostream>
using namespace std;
int countDer(int n)
{
 
    // base case
    if (n == 1 or n == 2) {
        return n - 1;
    }
 
    // Variable for just storing
    // previous values
    int a = 0;
    int b = 1;
 
    // using above recursive formula
    for (int i = 3; i <= n; ++i) {
        int cur = (i - 1) * (a + b);
        a = b;
        b = cur;
    }
 
    // Return result for n
    return b;
}
 
int main(){
    int test, num;
    cin >> test;
    int arr[test];
    for(int i=0; i<test; i++){
        cin >> num;
        arr[i] = countDer(num);
        
    }
    for(int i=0; i<test ;i++){
        cout << arr[i] << endl;
    }

}

    