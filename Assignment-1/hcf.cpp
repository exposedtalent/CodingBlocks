#include<iostream>
using namespace std;

int hcf(int a, int b){
    while(b > 0){
        int temp = b;
        b = a%b;
        a = temp;

    }
    return a;
}

int main(){
    int num;
    cin >> num;
    int *arr = new int[num];
    for(int i=0; i<num; i++){
        cin >> arr[i];
    }

    int res = arr[0];
    for(int i=0; i<num; i++){
        res = hcf(res, arr[i]);
    }
    cout << res << endl;
    
}