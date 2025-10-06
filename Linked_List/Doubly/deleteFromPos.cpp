// Delete a Doubly Linked List node at a given position

#include <iostream>
using namespace std;

struct Node{
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

    Node* temp = head;
    cout << "Original List: ";
    while(temp != NULL){
        cout << temp->data;
        if(temp->next != NULL) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;

    if(head == NULL){   // Edge case: if the list is empty
        cout << "Linked List is empty.\n";
    }

    int pos;
    cout << "Enter position from where to delete node: ";
    cin >> pos;

    Node* curr = head;
    // traverse to the node at the given position
    for(int i = 0; i < pos && curr != NULL; i++){
        curr = curr->next;
    }

    if(curr == NULL){   // position exceeds list length, no deletion
        cout << "Position exceedss the list length.\n";
    }

    // if the node to delete is not the first node update previous node's next
    if(curr->prev != NULL){
        curr->prev->next = curr->next;
    }

    // if the node to delete is not the last node update next node's prev
    if(curr->next != NULL){
        curr->next->prev = curr->prev;
    }

    // if deleting the head, move head pointer to next node.
    if(head == curr){
        head = curr->next;
    }
    delete curr;    // free memory

    temp = head;
    cout << "List after deletion: ";
    while(temp != NULL){
        cout << temp->data;
        if(temp->next != NULL) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;

    delete temp;    // free memory
    
    return 0; 
}