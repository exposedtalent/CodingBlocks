#include<iostream>
using namespace std;
int main() {
	int n;
	cin >>n;

    for (int i = 1; i <= n; i++) {

        for(int j = 1; j <= i; j++) {
            cout << j;
        }

        for(int j = 1; j <= n -i ; j++) {
            cout << "*";
        }   
        cout << endl;

    }
}
// Prints this for 5
// 1****
// 12***
// 123**
// 1234*
// 12345