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

Node* getNode(Node* head, int index){
    // PASS BY VALUE SO THE CHANGES IN THE HEAD WIL NOT GO TO THE ACTUAL HEAD OF 
    // LINKE LIST
    int i =0;
    while(i < index && head != NULL){
        head = head->next;
        i++;
    }
    return head;
}
Node* getTail(Node* head){
    // PASS BY VALUE SO THE CHANGES IN THE HEAD WIL NOT GO TO THE ACTUAL HEAD OF 
    // LINKE LIST
    while(head->next != NULL){
        head = head->next;
    }
    return head;
}
void insertAtHead(Node*& head, int data){
    // Create a node
    Node * n = new Node(data);
    // Asssign the new node to the headers
    n->next = head;
    // reassign the head pointer
    head = n;

}
void inserAtTail(Node*& head, int data){

    if(head == NULL){
        
        insertAtHead(head,data);
        return;

    }

    Node* tail = getTail(head);
    Node* n = new Node(data);
    tail->next = n;
}
void insertAtIndex(Node*& head,int data, int index){
    if(index == 0){
        insertAtHead(head,data);
    }
    if(index < 0){
        // the index is negative
        return;
    }
    // Get the prev
    Node* prev = getNode(head, index-1);
    if(prev == NULL){
        // user has given a index that is greater than the len of linked list
        cout << "Index greater than the len of the linked list" << endl;
        return;
    }
    //  Create a new node
    Node* n =new Node(data);
    // Assign the new node to the prev's next
    n->next = prev->next;
    // Assign the prev to the new node
    prev->next = n;
}
void deleteFromHead(Node*& head){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromIndex(Node*& head, int index){
    if(index == 0){
        deleteFromHead(head); 
        return;
    }
    else if( index < 0){
        return;
    }

    Node* cur = getNode(head, index);
    if(cur == NULL){
        //  index is greater equal to the len of th linked list
        return;
    }
    Node* prev = getNode(head, index-1);
    prev->next = cur->next;
    delete cur;
}

void deleteFromTail(Node*& head){
    
    if(head == NULL){
        return;
    }
    else if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    Node* prev = NULL;
    Node* tail = head;

    while(tail->next != NULL){
        prev = tail;
        tail = tail->next;
    }
    prev->next = NULL;
    delete tail;

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
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);

    insertAtIndex(head, 3, 2);
    print(head);
    insertAtIndex(head,6, 10);
    print(head);

    inserAtTail(head,9);
    inserAtTail(head,8);
    print(head);

    deleteFromHead(head);
    print(head);

    deleteFromIndex(head, 2);
    print(head);

    deleteFromTail(head);
    print(head);

    return 0;
}