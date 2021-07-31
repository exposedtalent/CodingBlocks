
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

void mirror(node* root){
    if( root == NULL){
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}
int main(){
    node* root = NULL;
    root = buildTree();
    
    preOrder(root);
    cout << endl;

    mirror(root);
    cout << endl;

    preOrder(root);
    cout << endl;


    return 0;
    
}
// Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1