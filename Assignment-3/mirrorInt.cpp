#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void mirrorrInveseOfANumber(){
    int num = 0;
    cin >> num;
    int temp = num;

    vector<int> arr;

    while(num){
        arr.push_back(num % 10);
        num /= 10; 
    }
    vector<int> newArr(arr.size());
    for(int i = 0; i <arr.size();i++){
        int num = arr[i];
        newArr[num - 1] = (i + 1);
    }
    reverse(newArr.begin(), newArr.end());
    int newNum = 0;
    for(int i = 0; i <newArr.size(); i++){
        newNum = newNum * 10 + newArr[i];
    }
    
    // cout << temp << " " << newNum << endl;    // reverse(newArr.begin(), newArr.end());

    if(temp == newNum){
        cout << "true" << endl;

    }
    else{
        cout << "false" << endl;
    }

}

int main(){
    mirrorrInveseOfANumber();
    return 0;
}

