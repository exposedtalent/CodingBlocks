#include<iostream>
#include<vector>
using namespace std;

// Used this for generic stack which can be anything
template <typename T> 
class stack {
    vector<T> v;

    public:
        void push(T data){
            v.push_back(data);
        }
        void pop(){
            v.pop_back();
        }
        int top(){
            return v[v.size()-1];
        }
        int size(){
            return v.size();
        }
        bool empty(){
            return v.size() == 0;
        }
        
};

int main(){

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "size = " << s.size() << endl;

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    cout << "size = " << s.size() << endl;
    s.empty() ? cout << "true" << endl : cout << "false" << endl;

    return 0;
}