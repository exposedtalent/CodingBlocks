#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MinHeap {
    vector<int> v;

    void heapify(int i){
        int min = i;
        int left = 2*i;
        int right = 2*i +1;

        if(v[left] < v[right] && v[left] < v[min]){
            min = left;
        }
        if(v[right] < v[min] && v[right] < v[min]){
            min = right;
        }
        if(min != i){
            swap(v[i], v[min]);
            heapify(min);
        }
    }
    public:
        MinHeap(){
            // reserve the 0th index
            v.push_back(-1);
        }
        void push(int data){
            v.push_back(data);
            int child = v.size() - 1;
            int parent = child  /2;

            while(child > 1 && v[child] < v[parent]){
                swap(v[child], v[parent]);
                child = parent;
                parent=  child/2;
            }
        }

        void pop(){
            swap(v[1]], v[v.size()-1]);
            v.pop_back();
        }
        int top(){
            return v[1];
        }
        bool isEmpty(){
            return v.size() == 1;
        }
        int size(){
            return v.size() - 1;
        }
        
};

int main(){

    MinHeap minHeap;
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