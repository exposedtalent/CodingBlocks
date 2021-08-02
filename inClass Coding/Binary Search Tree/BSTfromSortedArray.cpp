#include<iostream>
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


node* buildBST(int* arr, int s, int e){
    if(s > e){
        return NULL;
    }
    int m = s + (e-s)/2;
    node* root = new node(arr[m]);
    root->left = buildBST(arr, s , m-1);
    root->right = buildBST(arr, m+1 , e);

}

int main(){
    int arr[] = {3,5,7,10,13,15,17};
    
    int n = sizeof(arr)/sizeof(int);
    node* root = NULL;
    root = buildBST(arr, 0 , n-1);
    
    return 0;
    
}