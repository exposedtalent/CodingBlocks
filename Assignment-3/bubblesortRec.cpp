#include<iostream>
using namespace std;

void bubblesort(int arr[], int n){
    if(n == 1){
        return;
    }
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    bubblesort(arr,n-1);

}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n ; i++){
        cin >> arr[i];
    }
    int size = sizeof(arr)/ sizeof(arr[0]);
    bubblesort(arr, size);

    for(int i = 0; i < n ; i++){
        if(i == n -1){
            cout << arr[i];
        }
        else{
            cout << arr[i] << " ";
        }
    }

}

