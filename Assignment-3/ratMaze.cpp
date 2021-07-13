#include<iostream>
using namespace std;

bool doesPathExist(char maze[][1000], char soln[][1000], int m, int n, int i, int j) {
	if(i == m || j == n) {
		// you have crossed the boundaries of the grid
		return false;
	}

	if(i == m-1 and j == n-1) {

		// you are already at the dst i.e. bottom right
		soln[i][j] = '1';
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		soln[i][j] = '0';
		return true;
	}

	// I am standing at the (i, j)th cell, and I want to know if there exists a path
	// from the (i, j)th cell to the dst (m-1, n-1)

	
	// If the (i, j)th cell is blocked, definitely no path exists
	if(maze[m-1][n-1] == 'X') {
		return false;
	}
    if(maze[i][j] == 'X') {
		return false;
	}

	// otherwise, a path may or maynot exists

	soln[i][j] = '1';
    bool fromDown = false;
	// go right
	bool fromRight = doesPathExist(maze, soln, m, n, i, j+1);
    if(fromRight == true){
        return true;
    }
    else{
        // go down
         fromDown  = doesPathExist(maze, soln, m, n, i+1, j);
    }
	// backtracking
	soln[i][j] = '0';

	return fromRight || fromDown;

}

int main(){
    int m,n;
    cin >> m >> n;

    char arr[1000][1000];
    char sol[1000][1000];

    for(int i=0; i<m; i++){
        for(int j=0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j < n; j++){
            sol[i][j] = '0';
        }
    }
    // for(int i=0; i<m; i++){
    //     for(int j=0; j < n; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i=0; i<m; i++){
    //     for(int j=0; j < n; j++){
    //         cout << sol[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    int num = doesPathExist(arr, sol, m, n, 0, 0);
    if (num == 0){
        cout << -1;
    }
}

