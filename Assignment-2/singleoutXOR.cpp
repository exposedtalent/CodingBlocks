#include<iostream>
using namespace std;
int XOR(int arr[], int num){
    int temp = arr[0];
    for(int i = 1; i < num; i++){
        temp = temp ^ arr[i];
    }
    return temp;
}
int main(){
    int num;
    cin >> num;
    int arr[num];

    for(int i=0; i < num; i++){
        cin >> arr[i];
    }
    int x = XOR(arr, num);
    cout << x << endl;
    
}