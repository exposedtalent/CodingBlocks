#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool mycomp(string a, string b){
    
    if(a.find(b) == 0 or b.find(a) == 0){
        return a.length() > b.length();
    }
    
    return a < b;

}
void stringSort(){
    int n = 0;
    cin >> n;

    vector<string> v;

    for(int i = 0; i < n; i++){
        string s = v[i];
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), mycomp);
    for(auto i : v){
        cout << i << endl;
    }
}


int main(){

    stringSort();
    return 0;
}
