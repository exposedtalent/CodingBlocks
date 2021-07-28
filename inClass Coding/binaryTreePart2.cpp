// design a recursive algorithm to builld a binary tree given its pre-order traversal algorithm

#include<iostream>
#include<algorithm>
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


void preOrder(node* root){
    if(root == NULL){
        // root represents an empty tree
        cout << "-1 ";
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


void inOrder(node* root){
    if(root == NULL){
        // root represents an empty tree
        cout << "-1 ";
        return;
    }
    inOrder(root->left);
    cout << " " << root->data <<  " ";
    inOrder(root->right);
}

void postOrder(node* root){
    if(root == NULL){
        // root represents an empty tree
        cout << "-1 ";
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << " " << root->data <<  " ";
}

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
int main(){
    node* root = NULL;
    root = buildTree();

    cout << "Pre Order : "; 
    preOrder(root);
    cout << endl;

    cout << "In Order : "; 
    inOrder(root);
    cout << endl;

    cout << "Post Order : "; 
    postOrder(root);
    cout << endl;
    
    return 0;
    
}
// Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1