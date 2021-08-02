#include<iostream>
using namespace std;
// Given a BST, tranform the BST to a Sorted Linked List
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

class Pair{
    public:
        node* head;
        node* tail;

};

Pair sortedLinkList(node* root){
    Pair p;
    
    if(root == NULL){
        p.head = NULL, p.tail = NULL;
        return p;
    }

    Pair pL = sortedLinkList(root->left);
    
    if(pL.head != NULL){
        pL.tail->right = root;
        p.head = pL.head;
    }
    else{
        p.head = root;
    }
    
    Pair pR = sortedLinkList(root->right);
    if(pR.head != NULL){
        root->right = pR.head;
        p.tail = pR.tail;
    }
    else{
        p.tail = root;
    }

    return p;

}

void print(node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->right;
    }
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
    
    print(root);
    return 0;
    
}