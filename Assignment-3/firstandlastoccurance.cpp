#include<iostream>
using namespace std;

int firstoccur(int arr[], int num, int target, int i){
    if(i == num){
        return -1;
    }
    
    if(arr[i] == target){
        return i;
    }

    return firstoccur(arr, num, target, i+1);
}
int lastoccur(int arr[], int num, int target, int i){
    if(i < 0){
        return -1;
    }
    
    if(arr[i] == target){
        return i;
    }

    return lastoccur(arr, num, target, i-1);
    
}


int main(){
    int num, target;
    cin >> num >> target;
    int *arr = new int[num];

    for(int i = 0; i < num; i++){
        cin >> arr[i];
    }
    cout << firstoccur(arr, num, target,0) << " ";
    cout << lastoccur(arr, num, target, num-1);
    

}
