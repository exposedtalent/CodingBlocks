#include<iostream>
using namespace std;
int main () {
	int num; 
	cin >> num;
	
    int space = (num+1)/2-1;
    for(int i = 1; i <= (num+1)/2; i++){

        for(int j = 1; j <= space; j++){
            cout << "  ";
        }

        for(int k = 1; k <= 2*i-1; k++){
            cout << "* ";
        }

        space--;
        cout << endl;

    }
    int star = num-2;
    for(int i = 1; i <= (num/2); i++){

        for (int j = 1; j <= i; j++){
            cout << "  ";
        }

        for(int j = 1; j <= star; j++){
            cout << "* ";
        }
        star -= 2;
        cout << endl;
        
    }

}
// Prints this for 5
//     * 
//   * * * 
// * * * * * 
//   * * * 
//     * 