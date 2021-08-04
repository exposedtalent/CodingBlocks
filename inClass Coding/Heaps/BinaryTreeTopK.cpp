#include<iostream>
#include<queue>
//  QUESTION: 
// Given an inf stream of non-negative int, design aan algo to output the top-K int every time you encounter -1.
using namespace std;
void print(priority_queue<int, vector<int> , greater<int> > minHeap){

    while(!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}
int main(){
    int k;
    cin >> k;

    int x;
    priority_queue<int, vector<int> , greater<int> > minHeap;
    int cnt = 0;

    while(true){
        cin >>x;
        if(x == -1){
            print(minHeap);
        }
        else{
            if(cnt < k){
                minHeap.push(x);
                cnt++;
            }
            else{
                if(x > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(x);
                }
            }
        }
    }

    return 0;
}