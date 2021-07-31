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

void rightView(node* root, int curLev, int& maxLevel){
    if(root == NULL){
        return;
    }
    if(maxLevel < curLev){
        cout << root->data << " ";
        maxLevel = curLev;
    }
    rightView(root->right, curLev +1, maxLevel);
    rightView(root->left, curLev +1, maxLevel);

}
int main(){
    node* root = NULL;
    root = buildTree();

    int lev = 0, max = -1;
    rightView(root, lev, max );
    
    return 0;
    
}