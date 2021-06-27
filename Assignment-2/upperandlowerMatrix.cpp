#include<iostream>
using namespace std;

int main(){
    int num1 ,num2 ;

    cin >> num1;
    cin >> num2;
    int arr[num1][num2];
    for(int i = 0; i < num1; i++){
        for(int j = 0; j < num2; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < num1; i++){
        for(int j = 0; j < num2; j++){
            if(i < j || i == j){
                cout << arr[i][j] << " ";
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    cout << "\n\n";
    for(int i = 0; i < num1; i++){
        for(int j = 0; j < num2; j++){
            if(i > j || i == j){
                cout << arr[i][j] << " ";
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    
}