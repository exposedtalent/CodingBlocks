
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

int numOfNodes(node* root){

    if(root == NULL){
        return 0;
    }

    int left = numOfNodes(root->left);
    int right = numOfNodes(root->right);

    return left + right + 1;
}

int sumOfNodes(node* root){

    if(root == NULL){
        return 0;
    }

    int left = numOfNodes(root->left->data);
    int right = numOfNodes(root->right->data);

    return left + right + root->data;
}

int main(){
    node* root = NULL;
    root = buildTree();
    cout << " Number of nodes " << numOfNodes(root) << endl;
    cout << " Sum of nodes " << sumOfNodes(root) << endl;
    return 0;
    
}
// Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1