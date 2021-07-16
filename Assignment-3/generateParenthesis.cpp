#include<iostream>
#include<vector>
using namespace std;
// leetcode.com/problem/generate-parenthesis/

class Solution{
    void parathesis(int index, int n, int open, int close, string &ch, vector<string>& res){
        if(index == 2*n){
            res.push_back(ch);
            return;
        }
        if(open < n){
            ch.push_back('(');
            parathesis(index +1, n, open+1, close, ch, res);
            //backtracking
            ch.pop_back();
        }
        if(close < open){
            ch.push_back(')');
            parathesis(index +1, n, open, close+1, ch, res);
            //backtracking
            ch.pop_back();
        }
    }   

    public:
        vector<string> generateParentthesis(int n){
            vector<string> result;
            string ch = "";
            parathesis(0, n, 0, 0, ch, result);

            return result;
        }
};