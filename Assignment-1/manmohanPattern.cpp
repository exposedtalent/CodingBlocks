#include<iostream>
using namespace std;
int main () {
	int num; 
	cin >> num;
	
    cout << "1" << endl;

    for(int i = 1; i <= num; i ++){

        for(int j = 1; j <= i+1; j++){
            if(j == 1 || j == i+1){
                cout << i;
            }
            else{
                cout << 0;
            }
            
        }
        cout << endl;

    }

}
// Prints this for 
// 1
// 11
// 202
// 3003
// 40004
// 500005
