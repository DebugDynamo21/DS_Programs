// Deletion at beginning (Removal of first node) in a Linked List.

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node (int x){
        data = x;
        next = NULL;
    }
};

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    if(head == NULL){   // Check if the list is empty.
        cout << "List is empty! ";
    }

    cout << "Original list: ";  //  Print original list
    Node *curr = head;
    while(curr != NULL){    
        cout << curr->data;
        if(curr->next != NULL) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    Node* ptr = head;   // Store the current head in a temporary variable
    head = head->next;  // Move the head pointer to the next node
    delete ptr ;        // Free the memory of the old head node

    cout << "List after deletion of first node: ";
    curr = head;
    while(curr != NULL){
        cout << curr->data;
        if(curr->next != NULL) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    return 0; 
}