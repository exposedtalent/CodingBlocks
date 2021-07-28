
#include<iostream>
#include<algorithm>
using namespace std;

template<typename T>
class node{
    public:
        T data;
        node<T>* left;
        node<T>* right;

        node(T data){
            this->data = data;
            this->left = this->right = NULL;
        }
};

template<typename T>
void preOrder(node<T>* root){
    if(root == NULL){
        // root represents an empty tree
        cout << "-1 ";
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

template<typename T>
void inOrder(node<T>* root){
    if(root == NULL){
        // root represents an empty tree
        cout << "-1 ";
        return;
    }
    inOrder(root->left);
    cout << " " << root->data <<  " ";
    inOrder(root->right);
}

template<typename T>
void postOrder(node<T>* root){
    if(root == NULL){
        // root represents an empty tree
        cout << "-1 ";
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << " " << root->data <<  " ";
}

int main(){
    
    node<int> *root = NULL;
    
    root  = new node<int>(10);
    root->left = new node<int>(20);
    root->right = new node<int>(30);
    root->left->left = new node<int>(40);
    root->left->right = new node<int>(50);
    root->right->right = new node<int>(60);
    root->left->right->left = new node<int>(70);

    preOrder(root);
    cout << endl;

    inOrder(root);
    cout << endl;

    postOrder(root);
    cout << endl;
    return 0;
    
}