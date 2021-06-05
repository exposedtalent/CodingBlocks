#include<iostream>
using namespace std;
int main () {
	int num; 
	cin >> num;
	

    for(int i = 1; i <= num; i ++){

        for(int j = 1; j <= num - i; j++){
            cout << " ";
            
        }
        if(i == 1 || i == num){
            for(int j = 1; j <= num; j++){
                cout << "*";    
            }
            
        }
        else{
            for(int j = 1; j <= num; j++){
                if(j == 1 || j == num){
                    cout << "*";
                }
                else{
                    cout<< " ";
                }
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
