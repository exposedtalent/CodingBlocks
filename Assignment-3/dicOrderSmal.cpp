
#include<iostream>
#include<set>
using namespace std;
set permutations1(string inp, int i, set<string> s){
	// base case 
	if(inp[i] == '\0'){
		s.insert(inp);
		return s;
	}

	for(int j = i; inp[j] != '\0'; j++){
		swap(inp[i],inp[j]);
		permutations1(inp, i++, s);
		swap(inp[i], inp[j]);
	}
}
int main() {
	string inp;
	cin >> inp;
	set<string> s;
	permutations1(inp, 0, s);

	for(auto x: s){
		if(inp > x){
			cout << x << endl;
		}
		else{
			break;
		}
	}

	return 0;
}