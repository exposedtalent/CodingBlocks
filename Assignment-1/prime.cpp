#include<iostream>
using namespace std;
int main () {
	int num1, num2, flag;
	num1 = 2;
    cin >> num2;
    
	for(int i = num1; i <= num2; i++){
       
        if( i == 1 || i == 0){
            continue;
        }
        for(int j = 2; j <= i/2; ++j){
            if(i % j == 0){
                flag = 0;
                break;
            }
        }
        if( flag == 1){
            cout << i;
        }
	}

}