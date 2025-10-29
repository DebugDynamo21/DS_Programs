#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
};

Node* insertAtEnd(Node* tail, int value){
    Node* newNode = new Node(value);
    if(tail == NULL){
        tail = newNode;

        newNode->next = newNode;
    }
    else{
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}

void printList(Node* last){
    if(last == NULL){
        return;
    }

    Node* head = last->next;
    while(true){
        cout << head->data << " ";
        head = head->next;
        if(head == last->next){
            break;
        }
    }
    cout << endl;
}

int main(){
    Node *first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);

    Node *last = first->next->next;
    last->next = first;

    cout << "Original list: ";
    printList(last);

    last = insertAtEnd(last, 5);
    last = insertAtEnd(last, 6);

    cout << "After insertion: ";
    printList(last);
    return 0; 
}