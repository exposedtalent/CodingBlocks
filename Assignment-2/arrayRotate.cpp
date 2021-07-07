#include<iostream>
#include<algorithm>
using namespace std;
void rotatebyone(int arr[], int n){
    int temp;
    temp = arr[n - 1];
    for(int i = n-1; i >= 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}
int main(){
    int num, rotate;
    cin >> num;
    int arr[num];
    for(int i = 0; i < num; i++){
        cin >> arr[i];
    }
    cin >> rotate;
    for(int i = 0; i < rotate; i++){
        rotatebyone(arr,num);
    }

    for (int i = 0; i <num; i++){
        cout << arr[i];
    }




}