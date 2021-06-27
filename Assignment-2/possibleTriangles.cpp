#include<iostream>
#include <cstring>
using namespace std;

int isAnagram( int arr[] , int n){
    int count = 0;
    for( int i = 0; i < n; i++ ){
        for( int j =  i + 1; j < n;j++){
            for(int k = j +1; k < n; k++){
                if( arr[i] + arr[j] > arr[k] && arr[j] + arr[k] > arr[i] && arr[i] + arr[k] > arr[j])
                    count++;
            }
        }
    }
    return count;
}
int main () {
    int n;
    cin >> n;
    int arr [n];
    for( int i = 0; i < n ; i++ ){
        cin >> arr[i];
    }
    int num = isAnagram(arr, n);
    cout << num << endl;
    
}