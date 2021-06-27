#include<iostream>

using namespace std;

int main() {
	int row, col;
	cin >> row >> col;

	int mat[row][col];
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			cin >> mat[i][j];
		}
	}

	// print the matrix wave column-wise
	for(int i=0; i<row; i++) {
        if(i % 2 == 0)
            for(int j=0; j<col; j++) {
                cout << mat[i][j] << " ";
            }
        else{
            for(int j = col - 1; j >= 0; j--){
                cout << mat[i][j] << " ";
            }
        }
		
	}
	cout << "END";
	
	return 0;
}
/*
    1 2 3 4 
    5 6 7 8 
    9 10 11 12 
*/