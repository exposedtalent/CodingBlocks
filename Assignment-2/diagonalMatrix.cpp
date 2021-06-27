#include<iostream>
using namespace std;
/*
    input 
    1 2 3 
    4 5 6
    7 8 9

    output
    1 2 4 7 5 3 6 8 9 
 */

int main(){

    int num1, num2;
    cin >> num1 >> num2;
    int arr[num1][num2];

    for(int i=0; i<num1; i++){
        for(int j=0; j<num2; j++){
            cin >> arr[i][j];
        }
    }
    

    
}