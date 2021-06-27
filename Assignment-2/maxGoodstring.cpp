#include<iostream>
using namespace std;
bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i'|| c == 'o' || c == 'u');
            
}
int longest( string str){
    int count = 0;
    int prev = 0;

    for (int i = 0; i < str.length();i++){
        if(isVowel(str[i])){
            count++;
        }
        else{
            prev = max(prev,count);
            count = 0;
        }
    }
    return max(prev,count);
}

int main(){
    string str;
    cin >> str;
    int ans = longest(str);
    cout << ans << endl;
}