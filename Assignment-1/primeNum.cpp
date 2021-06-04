#include <iostream>
using namespace std;

int main(){
    int input = 4;

    for(int i = 1; i <= input; i++){
        for(int j = 1; j <= input-i; j++){
            cout << " " ;
        }
        int num = i;
        for(int j = 1; j <= i;j++){
            cout << num;
            num++;
        }

        num = num - 2;
        for (int h = 0; h < i - 1; h++){
            cout << num;
            num--;
        }
        cout << "\n";



    }
    

}