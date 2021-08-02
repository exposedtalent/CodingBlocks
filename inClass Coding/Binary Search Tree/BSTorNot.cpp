#include<iostream>
#include<climits>
using namespace std;
// Given a BST, check if it a BST
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
int findMax(node* root){
    if(root == NULL){
        return INT_MIN;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}
int findMin(node* root){
    if(root == NULL){
        return INT_MAX;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}
bool isBST(node* root){
    if(root == NULL){
        return true;
    }
    int leftMax = findMax(root->left);
    int rightMin = findMin(root->right);

    if(leftMax <= root->data && root->data < rightMin && isBST(root->left) && isBST(root->right)){
        return true;
    }
    return false;
}
class triple{
    public:
        int min;
        int max;
        bool isBST;
};
triple isBSTEff(node* root){
    triple t;
    if(root == NULL){
        t.isBST = true;
        t.min = INT_MAX;
        t.max = INT_MIN;
        return t;
    }
    
    triple tL = isBSTEff(root->left);
    triple tR = isBSTEff(root->right);

    if(tL.max <= root->data && root->data < tR.min && tL.isBST && tR.isBST){
        t.isBST = true;
    }
    else{
        t.isBST = false;
    }

    t.min = min(root->data, min(tL.min, tR.min));
    t.max = max(root->data, max(tL.max, tR.max));

    return t;

}

bool isBSTOptimal(node* root, int min, int max){

    if(root == NULL){
        return true;
    }
    if(min < root->data && root->data <= max && isBSTOptimal(root->left, min, root->data) && isBSTOptimal(root->right, root->data, max)){
        return true;

    }
    return false;

}
int main(){

    node* root = NULL;

    root = new node(10);
    root->left = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(7);
    
    root->right = new node(15);
    root->right->left = new node(13);
    root->right->right = new node(17);
    
    isBST(root) ? cout << "true" << endl : cout << "false" << endl;
    isBSTEff(root).isBST ? cout << "true" << endl : cout << "false" << endl;
    isBSTOptimal(root, INT_MIN, INT_MAX) ? cout << "true" << endl : cout << "false" << endl;
    return 0;
    
}