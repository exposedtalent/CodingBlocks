
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

int height(node* root){

    if( root == NULL){
        return -1;
    }

    int hL = height(root->left);
    int hR = height(root->right);
    return 1 + max(hL, hR);
}

int diameter(node* root){

    if( root == NULL){
        // root represents an empty tree
        return 0;
    }

    int dL = diameter(root->left);
    int dR = diameter(root->right);

    int hl = height(root->left);
    int hr = height(root->right);

    return max(hl + hr + 2, max(dL, dR));
}

int main(){
    node* root = NULL;
    root = buildTree();
    cout << "Diameter : " << diameter(root) <<endl;
    return 0;
    
}
// Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1