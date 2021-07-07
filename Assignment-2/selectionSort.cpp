#include<iostream>
using namespace std;


int main(){
    int num;
    cin >> num;
    int arr[num];

    for(int i = 0; i < num; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < num; i++){
        int min = i;
        for(int j = i+1; j < num; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }

    for(int i = 0; i < num; i++){
        cout << arr[i] << endl;
    }
}