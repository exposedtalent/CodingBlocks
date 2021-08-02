
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int data){
            this->data = data;
            this->left = this->right = NULL;
        }
};

node* buildTree(){
    int x;
    cin >> x;

    node* root = new node(x);
    queue<node*>q;
    q.push(root);

    while(!q.empty()){
        int left, right;
        cin >> left >> right;
        node* front = q.front();
        q.pop();
        if(left != -1){
            front->left = new node(left);
            q.push(front->left);
        }
        if(right != -1){
            front->right = new node(right);
            q.push(front->right);
        }
    }
    return root;

}

void leverOrderPrintwithNewLine(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* front= q.front();
        q.pop();

        if(front == NULL){
            // you have visited a level, so print a new line
            cout << endl;
            //  you have visited a level, that also means you've seen all the children of the new element
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << front->data << " ";
            if(front->left != NULL){
                q.push(front->left);
            }

            if(front->right != NULL){
                q.push(front->right);
            }
        }

    }
    cout << endl;
}

int main(){
    node* root = NULL;
    root = buildTree();
    leverOrderPrintwithNewLine(root);
    return 0;
    
}
// Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1