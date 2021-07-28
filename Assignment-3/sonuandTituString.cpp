#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sonuAndTituString(){
    string a,b;
    cin >> a >> b;

    vector<int> f1(26,0), f2(26,0);

    for(char c : a){
        f1[c - 'a'];
    }
    for(char c : b){
        f2[c - 'a'];
    }

    int cnt = 0;
    for(int i=0; i< 26; i++){
        if(f1[i] != f2[i]){
            cnt += abs(f1[i]-f2[i]);
        }
    }
    cout << cnt << endl;
    
}

int main(){
    sonuAndTituString();
    return 0;
}

