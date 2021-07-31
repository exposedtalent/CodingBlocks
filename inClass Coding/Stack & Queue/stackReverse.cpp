#include<iostream>
#include<stack>
using namespace std;
//  Create a program to reverse a stack WITHOUT using another data structure

void insertAtBottom(stack<int>& s, int c){
    if(s.empty()){
        s.push(c);
        return;
    }
    int y = s.top();
    s.pop();
    insertAtBottom(s,c);
    s.push(y);
}

void reverse(stack<int>& s){
    if(s.empty()){
        return;
    }

    int c = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, c);

}

void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    print(s);
    reverse(s);
    print(s);

    return 0;
}