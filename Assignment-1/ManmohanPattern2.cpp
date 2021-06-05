#include<iostream>
using namespace std;
int main () {
	int num; 
	cin >> num;
    for(int i = 0; i <= num -1 ; i ++){
        for(int j = 1; j <= i+1; j++){
            if(i % 2 == 0){
                cout << 1;
            }
            else{
                if(j == 1 || j == i+1){
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
        }
        cout << endl;
    }
}
// Prints this for 
// 1
// 11
// 111
// 1001
// 11111