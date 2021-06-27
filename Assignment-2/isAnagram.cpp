#include<iostream>
#include <cstring>
using namespace std;

bool isAnagram( string str1, string str2 ){

    int freq[26] = {0};
    for( int i = 0; str1[i] != '\0'; i++ ){
        char c = str1[i];
        int index = c - 'a';
        freq[index]++;
    }
    int freq2[26] = {0};
    for( int i = 0; str2[i] != '\0'; i++ ){
        char c = str2[i];
        int index = c - 'a';
        freq2[index]++;
    }
    for( int i = 0; i < 26; i++ ){
        if( freq[i] != freq2[i] ){
            return false;
        }
    }
    return true;
}
int main () {
    string str1 = "";
    string str2 = "";
    cin >> str1 >> str2;
    isAnagram( str1, str2 ) ? cout << "true" << endl : cout << "false" << endl;
    
}