// Insert a Node at Front/Beginning of Doubly Linked List.

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node (int newNode){
        data = newNode;
        next = NULL;
        prev = NULL;
    }
};

int main(){
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;

    Node* curr = head;   // Pointer to traverse the list
    cout << "Original List: ";
    while(curr != NULL){
        cout << curr->data;
        if(curr->next != NULL) cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;

    Node* newNode = new Node(1);    // New Node to be inserted at front

    newNode->next = head;   // Linking newNode with head
    if(head != NULL)    
        head->prev = newNode;   // Linking head with newNode
    head=newNode;   // Updating head to newNode

    curr = head;   // Resetting curr to head to print the updated list
    
    cout << "List after insertion: ";
    while(curr != NULL){
        cout << curr->data;
        if(curr->next != NULL) cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;
    return 0; 
}