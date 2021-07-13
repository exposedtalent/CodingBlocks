#include<iostream>
using namespace std;

void majority(int arr[], int n){
    int max = 0;
    int index = -1;

    for(int i = 0; i < n;i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > max){
            max = count;
            index = i;
        }
    }

    if(max > n / 2){
        cout << arr[index] << endl;
    }
    else{
        cout << "No majority" << endl;
    }
    
}

int main(){
    int num;
    cin >> num;
    int *arr = new int[num];
    for(int i = 0; i < num ; i++){
        cin >> arr[i];
    }
    majority(arr, num);
    
}