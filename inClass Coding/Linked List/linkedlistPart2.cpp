#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};


void insertAtHead(Node*& head, int data){
    // Create a node
    Node * n = new Node(data);
    // Asssign the new node to the headers
    n->next = head;
    // reassign the head pointer
    head = n;

}

void deleteFromHead(Node*& head){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

int length(Node* head){
    int count = 0;
    while(head != NULL){ 
        head = head->next;
        count++;
    }
    return count;
}

int lengthRecursive(Node* head){
    if(head == NULL){
        return 0;
    }
    return lengthRecursive(head->next) + 1;
}

bool searchItr(Node* head, int  key){
    while(head != NULL){
        if(head->data == key){
            return true;
        }
        head = head->next;
    }
    return false;
}

bool searchRecursive(Node* head, int key){
    if(head == NULL){
        return false;
    }
    if(head->data == key){
        return true;
    }
    bool res = searchRecursive(head->next, key);
    if (res == true){
        return true; 
    }
    else{
        return false;
    }
}
void print(Node* head){
    while(head != NULL)
    {
        cout << head->data;
        head = head->next;
        if(head != NULL){
            cout << "->";
        }
    }  
    cout << endl;
}

int main(){

    Node* head = NULL;

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);

    cout << length(head) << endl;
    
    cout <<lengthRecursive(head) << endl;

    searchItr(head, 2) ? cout << "true" << endl : cout << "false" << endl;
    searchItr(head, 8) ? cout << "true" << endl : cout << "false" << endl;

    searchRecursive(head, 2) ? cout << "true" << endl : cout << "false" << endl;
    searchRecursive(head, 7) ? cout << "true" << endl : cout << "false" << endl;

    return 0;
}