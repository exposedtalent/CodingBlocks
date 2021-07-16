#include<iostream>
#include<set>
using namespace std;
void permutations(string inp, int i, set<string>& s){
	// base case 
	if(inp[i] == '\0')
	{
		s.insert(inp);
		return;
	}

	for(int j = i; inp[j] != '\0'; j++)
	{
		swap(inp[i],inp[j]);
		permutations(inp, i+1, s);
		swap(inp[i], inp[j]);
	}
}
int main() {
	string inp;
	cin >> inp;
	set<string> s;
	permutations(inp, 0, s);
	for(auto x: s)
	{	
        if(x > inp){
            cout << x << endl;
        }
        else{
            continue;
        }
	}

	return 0;
}