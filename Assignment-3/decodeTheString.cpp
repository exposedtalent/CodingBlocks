#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


string decodeTheString(string s, int& i){
    
    string res = "";
    
    if( i >= s.length()){
        return;
    }
    while (i < s.length()){
        if(s[i] >=  '0' and s[i] < '9'){
            int num = 0;
            while(s[i] >= '0' and s[i]  <= '9'){
                num = num *10 + (s[i] - '0');
                i++;
            }

            i++;
            string recRes = decodeTheString(s, i);
            for(int i = 0; i < num; i++){
                res+=  recRes;
            }
        }
        else if(s[i] == ']'){
            return res;
        }
        else{
            res.push_back(s[i]);
        }
        i++;
    }
    return res;
}


int main(){

    string s;
    cin >>s;
    int i =0;
    cout << decodeTheString(s,i);
    
    return 0;
}

