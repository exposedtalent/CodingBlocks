#include<iostream>;
using namespace std;
string reverseString(string str){
    reverse(str.begin(), str.end());
    str.insert(str.end(), ' ');
 
    int n = str.length();
 
    int j = 0;
 
    // Find spaces and reverse all words
    // before that
    for (int i = 0; i < n; i++) {
 
        // If a space is encountered
        if (str[i] == ' ') {
            reverse(str.begin() + j,
                    str.begin() + i);
 
            // Update the starting index
            // for next word to reverse
            j = i + 1;
        }
    }
 
    // Remove spaces from the end of the
    // word that we appended
    str.pop_back();
 
    // Return the reversed string
    return str;
}
int main(){
    string str;
    cin >> str;

    string str2 = reverseString(str);
    cout << str2;
}