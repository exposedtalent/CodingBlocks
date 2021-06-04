#include<iostream>
using namespace std;
int main () {
	int num; 
	cin >> num;
    
	for(int i = 1;i <= num; i++){
       int count = i;
        for( int j = 1 ; j <= i ; j++){
			cout << count << " " ;
            
		}
        int c = i;
		for(int j = 1; j <=  num -i; j++){
            c++;
			cout << c << " " ;
            
		}
        count++;
        cout << endl;

	}

}