#include<iostream>

using namespace std;
/*
  1 2 3 
  4 5 6
  7 8 9

  1 2 4 7 5 3 6 8 9 
 */
int main() {
	int m, n;
	cin >> m >> n;

	int mat[m][n];
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> mat[i][j];
		}
	}

	// print the matrix wave column-wise
	for(int j=0; j<n; j++) {
		if(j%2 == 0) {
			// print from top to bottom
			for(int i=0; i<m; i++) {
				cout << mat[i][j] << ", ";
			}
		} else {
			// print from bottom to top
			for(int i=m-1; i>=0; i--) {
				cout << mat[i][j] << ", ";
			}
		}
		
	}
	cout << "END";
	
	return 0;
}
