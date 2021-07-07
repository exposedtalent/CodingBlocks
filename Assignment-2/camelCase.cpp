#include<iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    for(int i = 0;i<str.length(); i++){
        if(i == 0 && str[i] >= 'A' && str[i] <= 'Z'){
            cout << str[i];
        }
        else if(str[i] >= 'a' && str[i] <= 'z'){
            cout << str[i];
        }
        else if (str[i] >= 'A' && str[i] <= 'Z'){
            cout << "\n";
            cout << str[i];
        }
    }

}