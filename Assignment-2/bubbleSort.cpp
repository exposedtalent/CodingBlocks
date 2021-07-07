#include<iostream>
using namespace std;

int main(){

    int num;
    cin >> num;
    int arr[num];

    for(int i = 0; i <num ; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < num; i++){
        for(int j = 0; j <num - i - 1; j++){
            if(arr[j] > arr[j+1] ){
                swap(arr[j], arr[j+1]);
            }
        }
        
    }

    for(int i = 0; i < num ; i++){
        cout << arr[i] << endl;
    }
}