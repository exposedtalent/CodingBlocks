#include<iostream>
#include <cstring>
using namespace std;

void isrotate(char* str, int rotate, int len) {
    char temp = str[len - 1];
    for(int i = len - 1; i >= 0; i--){
        str[i] = str[i - 1];
    }
    str[0] = temp;
}

int main() {

	char str[] = "codingblocks";
    int rotate = 3;
    int len = strlen(str);
    cout << str << endl;
	isrotate(str, rotate, len);
    cout << str << endl;
	return 0;
}