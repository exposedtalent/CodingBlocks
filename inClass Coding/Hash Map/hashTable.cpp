// HashTable implementation using your own hash table
#include<iostream>
using namespace std;

class node{
    public :
        string key;
        int value;
        node* next;

        node(string key, int value){
            this->key = key;
            this->value = value;
            this->next = NULL;
        }

        ~node(){
            if(next){
                delete next;
            }
        }
};

class HashTable{
    int ts ; // TableSize
    int cs ; // currentSize
    node ** table; 
    float loadFactor;
    int hashFn(string key){
        int power = 0, idx= 0;
        for(int i=0; i<key.size(); i++){
            idx += (key[i]%ts) * (power%ts) ; 
            power = (power*61)%ts;
        }
        return idx%ts;
    }
    void transfer(node *head){
        node* temp = head;
        while(temp!= NULL){
            insert(temp->key, temp->value);
            temp = temp->next;
        }
        if(head != NULL) delete head;
    }
    void rehash(){
            int old_ts = ts;
            node ** old_table = table;

            ts *= 2;
            cs =0;
            table = new node*[ts];
            for(int i=0; i<ts; i++){
                table[i] = NULL;
            }
            for(int i=0; i<old_table; i++){
                transfer(old_table[i]);
            }

            delete [] old_table;
        }
    public :
        HashTable(int ts=7, loadFactor =0.7){
            this->ts = ts;
            this->cs = cs;

            table = new node*[ts];
            for(int i = 0; i < ts;i++){
                table[i] = NULL;
            }
            this->loadFactor = loadFactor;
        }


        void insert(string key, int value){
            // create a new node
            node* n = new node(key, value);

            // obtain the has function 
            int hash_ind = hashFn(key);

            // insert the node in the linked list at the hash index
            n->next = table[hash_ind];
            table[hash_ind] = n;

            // increment the currentSize
            cs++;
            float  loadF = cs / (ts * 1.0);
            if(loadF > loadFactor){
                rehash();
            }
        }

        node* search(string key){
            // obtain the hash index ussing the has function
            int hash_ind = hashFn(key);

            node* temp = table[hash_ind];
            while(temp){
                if(temp->key == key){
                    // found the key 
                    return temp;
                }
                temp = temp->next;
            }
            // key does not exist 
            return NULL;
        }
        void printlinkedist(node* head){
            while(head){
                cout << "(" << head->key << "," << head->value << ")" << endl;
                head = head->next;
                cout << endl;
            }
        }
        void print(){
            for(int i=0; i<ts;i++){
                cout << i << " ";
                printlinkedist(table[i]);
            }
        }

        int& operator [](string key){
            node* n = search(key);
            if(n == NULL){
                int garbage;
                insert(key, garbage);
                n = search(key);
            }

            return n->value;
        }

        
};



int main(){
    HashTable menu(7);
    // insert
    menu.insert("burger", 100);
    menu.insert("Pizza", 300);
    menu.insert("Momo", 200);
    menu.insert("Chai", 10);
    menu.insert("FrenchFries", 50);
    // print
    menu.print();
    // search
    string key = "burger";
    node* val = menu.search(key);
    cout << val->key << " " << val->value;

    menu['dosa'] = 100;
    menu['dosa'] += 10;
    
    return 0;
}