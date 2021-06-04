#include<iostream>
using namespace std;
int main() {
	char c;
	cin >> c;

	if(c >= 'a' && c <= 'z'){
		cout << "L";
	}
	else if( c >= 'A' && c <= 'Z'){
		cout << "U";
	}
	else{
		cout << "I";
	}
}