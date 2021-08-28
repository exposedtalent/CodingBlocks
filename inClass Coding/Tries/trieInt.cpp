#include <iostream>
using namespace std;

class node{
    public : 
        node* left, *right;
        bool terminal;
        node(){
            this->right = NULL;
            this->left = NULL;
        }
};
class trie{
    node* root;
    public:
        trie(){
            root = new node();
        }
        void insert(int x){
            node* temp = root;
            for(int i = 31; i >= 0; i--){
                int bit = (1<<i)&x;
                if(!bit){
                    // it   h bit of x is 0, check idf tempe has a left child or not and
                    if(!temp->left){
                        // temp does not have a left child
                        node* n = new node();
                        temp->left = n;
                    }
                    temp = temp->left;
                }
                else{
                    // ith bit of x is 1, chekc if tempe has a rught child or Not
                    if(!temp->right){
                        node* n = new node();
                        temp->right = n;
                    }
                    temp  = temp->right;
                }
            }
            temp->terminal = true;
        }

        bool search(int x){
            node* temp = root;
            for(int i = 31; i >= 0 ; i--){
                int bit = (1<<i)&x;
                if(!bit){
                    // ith bit of x is 0
                    // check if the tem node has a left child
                    if(temp->left == NULL){
                        return false;
                    }
                    temp = temp->left;
                }
                else{
                    // check if the temp node has a left child

                    if(temp->right == NULL){
                        return false;
                    }
                    temp = temp->right;
                }
            }
        }
};

int main(){
    int A[] = {2,5,8,10,25};
    int n = sizeof(A) / sizeof(int);

    trie t;
    for(int i =0; i <n;i++){
        t.insert(A[i]);
    }

    int Q[] = {1,2,3,4,5};
    int m = sizeof(Q) / sizeof(int);

    for(int i =0; i <m;i++){
        t.search(Q[i]) ? cout << Q[i] << " :true" << endl : cout << Q[i] << " : false" << endl;
    }
}