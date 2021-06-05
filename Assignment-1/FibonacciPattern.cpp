#include<iostream>
using namespace std;
int main() {
	int n;
	cin >>n;

    int first = 0;
    int second = 1;
	for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= i; j++){
            cout << first << "  ";
            int temp = first;
            first = second;
            second = temp + first;

        }
        cout << endl;
    }
}