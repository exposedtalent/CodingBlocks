#include<iostream>
#include<set>
#include<cstring>
using namespace std;

void generatePermutations(char inp[], int i, set<string>&s){

    if(inp[i] == '\0'){
        s.insert(string(inp));
        return;
    }

    for(int j = 0; j < strlen(inp); j++){
        swap(inp[i], inp[j]);
        generatePermutations(inp,i+1,s);
        swap(inp[i], inp[j]);
    }
}

int main(){
    char input[6];
    cin >> input;
    set<string> s;
    generatePermutations(input,  0, s);

	for(string str : s) {
		cout << str << endl;
	}


}