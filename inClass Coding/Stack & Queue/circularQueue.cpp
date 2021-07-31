
#include<iostream>
#include<queue>
using namespace std;
class circularQueue{
    int front, rear, cap, len;
    int* arr;
    public : 
        circularQueue(int cap = 8){
            this->cap = cap + 1;
            this->arr = new int[cap + 1];
            this->len = this->front = this->rear = 0;
        }

        void push(int data){
            if(front == (rear +1) % cap){
                // queue is full
            }
            else{
                rear = (rear +1) % cap;
                arr[rear] = data;
                len++;
            }
        }

        void pop(){
            if(front == rear){
                // queue is empty
            }
            else{
                front = (front + 1) % cap;
                len--;
            }
        }
        int getFront(){
            return arr[(front + 1) % cap];
        }
        bool empty(){
            return front == rear;

        }
        int size(){
            return len;
        }


};

void print(circularQueue q){
    while(!q.empty()){
        cout << q.getFront() << " ";
        q.pop();
    }
    cout << endl;
}
int main(){

    circularQueue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    print(q);

    return 0;
}
