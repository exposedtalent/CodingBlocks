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
    if(x == -1){
        return NULL;
    }
    node* root = new node(x);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void leverOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* front= q.front();
        q.pop();
        cout << front->data << endl;
        if(front->left != NULL){
            q.push(front->left);
        }

        if(front->right != NULL){
            q.push(front->right);
        }

    }
    cout << endl;
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

node* buildTree(int* pre, int& i, int* in, int s, int e){
    if(s > e){
        return NULL;
    }
    int rootD = pre[i++];

    node* root = new node(rootD);
    int k = -1;
    for(int i = s; i <= e; i++){
        if(in[i] == rootD){
            k = i;
            break;
        }
    }

    root->left = buildTree(pre, i, in, s, k-1);
    root->right = buildTree(pre, i, in, k+1, e);

    return root;

}

int main(){
    node* root = NULL;
    int pre[] = {10,20,40,50,70,30,60};
    int in[] = {40,20,70,50,10,30,60};
    int n = sizeof(in) / sizeof(int);
    int s = 0; 
    int e = n -1;
    int i = 0;

    root = buildTree(pre, i, in, s, e);
    leverOrderPrintwithNewLine(root);
    
    return 0;
    
}