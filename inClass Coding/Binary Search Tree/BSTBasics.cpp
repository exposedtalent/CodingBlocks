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

void inOrder(node* root){
    if(root == NULL){
        // root represents an empty tree
        cout << " ";
        return;
    }
    inOrder(root->left);
    cout << " " << root->data <<  " ";
    inOrder(root->right);
}

node* insertInBST(node* root, int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(data <= root->data){
        root->left = insertInBST(root->left, data);
    }
    else{
        root->right = insertInBST(root->right, data);
    }

    return root;
}

node* buildBST(){
    node* root= NULL;

    int data;
    cin>>data;

    while(data!= -1){
        root = insertInBST(root, data);
        cin >> data;
    }
    return root;
}

void range(node* root, int s, int e){
    if(root == NULL){
        return;
    }

    range(root->left, s,e);
    if(root->data >= s && root->data <= e){
        cout << root->data <<  " ";
    }
}
node* findMin(node* root){

    if(root == NULL){
        return NULL;
    }

    while(root->left != NULL){
        root = root->left;
    }
    // At this point the root points to the left most or min data

    return root;
}

node* findMax(node* root){

    if(root == NULL){
        return NULL;
    }

    while(root->right != NULL){
        root = root->right;
    }
    // At this point the root points to the right most or MAX data

    return root;
}

bool search(node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }

    else if(key < root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }

    return false;
}

node* del(node* root, int key){

    if(root == NULL){\
        // root represents an empty tree
        return root;
    }
    if(key < root->data){
        root->left = del(root->left, key);
        return root;
   }
    else if(key > root->data){
        root->right = del(root->right, key);
        return root;
    }
    else{
        // you're at a node whose data matched the key 
        if(root->left == NULL && root->right == NULL){
            //  you want to delete  a node with no children
            delete root;
            root = NULL;
            return root;
        }
        else{
            // you want to delete a node with children
            if(root->right == NULL && root->left != NULL){
                // you want to delete a node with only a left child
                node* temp = root->left;
                delete root;
                return temp;
            }
            else if(root->right != NULL && root->left == NULL){
                //  you want to delete  a node with only a right child
                node* temp = root->right;
                delete root;
                return temp;
            }
            else{
                // you want to delete a node with two children
                node* replace = findMax(root->left);
                swap(root->data, replace->data);
                del(root->left, replace->data);
                return root;
            }
        }
    }
}
int main(){
    node* root = NULL;
    
    root = buildBST();

    inOrder(root);
    cout << endl;
    int key;
    cin >> key;
    // search
    search(root, key) ? cout << "true" << endl : cout << "false" << endl;
    // Min & Max
    // node* min = findMin(root);
    // min != NULL ? cout << "Min: " << min->data : cout << "BST is empty" << endl;
    
    // node* max = findMax(root);
    // max != NULL ? cout << "Max: " << max->data : cout << "BST is empty" << endl;

    // // Range
    // int s,e;
    // cout << "s >> ";
    // cin >> s;
    // cout << "e >> ";
    // cin >> e;

    // cout << "range[ " << s <<  " , " << e <<" ]";
    // range(root, s, e);

    del(root, key);
    inOrder(root);
    
    

    return 0;
    
}