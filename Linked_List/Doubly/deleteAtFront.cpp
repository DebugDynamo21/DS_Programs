// Deletion at beginning (Removal of first node) in a Doubly Linked List

#include <iostream>
using namespace std;

struct Node {   // Node structure
    int data;
    Node* next;
    Node* prev;

    Node(int new_node){
        data = new_node;
        next = prev = NULL;
    }
};

int main(){
    Node* head = new Node(10);  // Creating nodes and linking them
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    if(head == NULL){   // Check if list is empty
         cout << "Linked List is empty.\n";
    }

    Node* curr = head;  // Display original list
    cout << "Original List: ";
    while(curr != NULL){
        cout << curr->data;
        if(curr->next != NULL) cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;

    Node* temp = head;  // Node to be deleted
    head = head->next;  // Move head to next node

    if(head != NULL){   // Adjust the prev pointer of new head
        head->prev = NULL;  // New head's prev should be NULL
    }

    cout << "List after deletion: ";
    curr = head;    
    delete temp;    // Free memory of deleted node

    // Display modified list
    while(curr != NULL){
        cout << curr->data;
        if(curr->next != NULL) cout << " <-> ";
        curr = curr->next;
    }
    delete curr; // Free memory of curr pointer
    cout << endl;

    return 0; 
}