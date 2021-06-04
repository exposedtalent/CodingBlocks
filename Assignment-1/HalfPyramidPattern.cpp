#include<iostream>
using namespace std;
int main () {
	int num; 
	cin >> num;
	for(int i = 1;i <= num; i++){
        int count = i;
        for( int j = 1 ; j <= i ; j++){
			cout << j << " " ;
            count++;
		}
		for(int j = 1; j <=  num -i; j++){
			cout << "  ";
		}
        
		
        cout << endl;

	}

}