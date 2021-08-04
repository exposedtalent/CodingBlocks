#include<iostream>
#include<queue>
using namespace std;

class Comparator{
    public:
        bool operator()(int a, int b){
            return a > b; //MIN Heap
            // return a < b; // MAX Heap
        }
};

int main(){
    priority_queue<int, vector<int>, Comparator > minHeap;
    minHeap.push(5);
    minHeap.push(0);
    minHeap.push(3);
    minHeap.push(7);
    minHeap.push(1);
    minHeap.push(2);
    minHeap.push(6);
    minHeap.push(4);

    while(!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    return 0;
}