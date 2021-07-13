#include<iostream>
#include <vector>
using namespace std;

int main(){

    int count = 0;
    int num;
    bool found = false;
    vector<int> v;
    while(count >= 0 ){
        cin >> num;
        // if pos num
        if(num >= 0){
            count = count + num;
            v.push_back(num);
        }

        // if neg num
        else{
            // check if the total is neg with num
            int temp = count;
            temp += num;
            if(temp >= 0 ){
                count = temp;
                v.push_back(num);

            }
            else{
                break;
            }
        }
        
    }
    for( int i = 0; i <v.size(); i++){
        cout << v[i] << endl;
    }
    
}