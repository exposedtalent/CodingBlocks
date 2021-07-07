#include<iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int arr[num];
    int max = -1000000000;

    for(int i=0; i < num; i++){
        cin >> arr[i];
    }

    for(int i=0; i < num; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout << max << endl;
}