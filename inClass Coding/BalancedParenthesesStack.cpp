// https://leetcode.com/problems/valid-parentheses/solution/

#include<iostream>
#include<stack>
using namespace std;

bool isValid(string str){
    stack<char> s;
    for(char ch : str){
        switch(ch){
            case '(':
            case '[':
            case '{': s.push(ch); break;
            case ')':
                if(!s.empty() && s.top ()== '('){
                    s.pop();
                }
                else{
                    return false;
                }
                break;
            case ']':
                if(!s.empty() && s.top ()== '['){
                    s.pop();
                }
                else{
                    return false;
                }
                break;
            case '}':
                if(!s.empty() && s.top ()== '{'){
                    s.pop();
                }
                else{
                    return false;
                }
                break;

        }
    }
    if(s.empty()){
        return true;
    }
}
int main(){
    string str("{[()]}");
    isValid(str) ? cout << "true" << endl : cout << "false" << endl;
    return 0;
}