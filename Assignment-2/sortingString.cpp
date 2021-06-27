#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;

bool compare(string a, string b)
{
    // Check if a string is present as
    // prefix in another string, then
    // compare the size of the string
    // and return the larger size
    if (a.compare(0, b.size(), b) == 0 || b.compare(0, a.size(), a) == 0)
  
        return a.size() > b.size();
  
    // Else return lexicographically
    // smallest string
    else
        return a < b;
}
int main() {
	int n;
    cin>>n;
    string s;
    string str[n];
    for(int i=0;i<n;i++){
        cin>>s;
        str[i]=s;
    }
    sort(str,str+n,compare);
    for(int i=0;i<n;i++){
        cout<<str[i]<<endl;
    }
}