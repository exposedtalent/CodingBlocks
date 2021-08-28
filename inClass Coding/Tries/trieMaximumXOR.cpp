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
        int helper(int x){
            node* temp = root;
            int XOR = 0; //to store the max possible XOR between x & nps. inside the trie
            for(int i = 31; i>= 0;i--){
                int bit = (1<<i) & x;
                if(!bit){
                    // ith bit is 0 
                    // to max XOR, check if the temp node has a right child ir bit 1
                    if(temp->right){
                        // temp node has a right child
                        XOR += (1<<i);
                        temp = temp->right;
                    }
                    else{
                        // temp node does not have a right child
                        temp = temp->right;
                    }
                }
                else{
                    // ith bit is 1 
                    //  to max XOR check if the temp has a left child
                    if(temp->left){
                        // temp node has a left child
                        XOR += (1<<i);
                        temp = temp->left;
                    }
                    else{
                        // temp does not have a left child
                        temp = temp->left;
                    }
                }
            }

            return XOR;
        }
        int maxXOR(int* A, int n){
            int finalAns = 0;
            for(int i = 0; i < n; i++){
                insert(A[i]);
                finalAns = max(finalAns,helper(A[i]));
            }
            return finalAns;
        }
};

int main(){
    int A[] = {2,5,8,10,25};
    int n = sizeof(A) / sizeof(int);

    trie t;
    cout << t.maxXOR(A, n) << endl;
}