// Deletion at end (Removal of last node) in a Doubly Linked List

#include <iostream>
using namespace std;

struct Node {   // Structure of a node
    int data;
    Node* next;
    Node* prev;

    Node(int newNode){
        data = newNode;
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

    if(head == NULL){   // Edge case: if the list is empty
        cout << "Linked List is empty.\n";
    }

    if(head->next == NULL){ // Edge case: if the list has only one node
        delete head;
    }

    cout << "Original List: ";
    Node* curr = head;
    while(curr != NULL){    // Displaying the original list
        cout << curr->data;
        if(curr->next != NULL) cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;

    Node* temp = head;  // Traversing to the last node
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;    // Adjusting the pointers to remove the last node
    delete(temp);   // Deleting the last node


    curr = head;
    cout << "List after deletion: ";
    while(curr != NULL){    // Displaying the list after deletion
        cout << curr->data;
        if(curr->next != NULL) cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;
    return 0; 
}