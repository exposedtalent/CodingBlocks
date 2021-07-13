#include<iostream>
using namespace std;
int* add(int x, int y){
    int *z = new int;
    *z = x+ y ;
    return z;
}

int main(){
    // int *p = new int;
    // *p = 20;
    // cout << *p << endl;
    // delete(p);
    // p = NULL;
    
    // int x =10;
    // int y = 20;
    // int *ptr = add(x, y);
    // cout << *ptr<< endl;
    // delete ptr;
    // ptr = NULL;

    // To make a 2-d array dynamiically
    int m,n;
    cin >> m;
    cin >> n;

    int ** ptr = new int*[m];
    for(int i=0; i<m; i++){
        ptr[i] = new int[n];
    }
    cout << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> ptr[i][j];

        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << ptr[i][j] << " ";
            
        }
        cout << endl;
    }
    for(int i=0; i<m; i++){
        delete [] ptr[i];
    }
    
    delete [] ptr;
    ptr = NULL;
}