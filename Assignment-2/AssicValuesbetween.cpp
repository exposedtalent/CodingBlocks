#include<iostream>
#include <string>
using namespace std;

int main(){
    string str, str2;
    cin >> str;

    for(int i = 0; i < str.length() - 1; i++){
        char first = str[i];
        char second = str[i+1];
        int diff = second - first;
        cout << str[i] << diff;
    }
    cout << str[str.length() -1];
    
}