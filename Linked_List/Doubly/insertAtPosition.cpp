// Insert a Node at a specific position in Doubly Linked List

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev, *next;

    Node(int new_node){
        data = new_node;
        next = prev = NULL;
    }
};

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;

    // Print the original list
    cout << "Original Linked List: ";
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data;
        if(temp->next != NULL) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;

    int pos = 3, val = 3;

    Node* newNode = new Node(val);  // New Node to be inserted

    if(pos == 1){   // Insert at the beginning
        newNode->next = head;   // Link newNode with head

        if(head != NULL){   // If list is not empty, link head with newNode
            head->prev = newNode;
        }
        head = newNode;  // Update head to newNode
    }
    else {  // Insert at given position (not at the beginning)
        Node* curr = head;  
        for(int i = 1; i < pos - 1 && curr != NULL; i++){
            curr = curr->next;
        }

        if(curr == NULL){   // If position is out of bounds
            cout << "Position out of bounds." << endl;
            delete newNode; // Free the allocated memory
            return 0;
        }

        newNode->prev = curr;   // Link newNode with previous node
        newNode->next = curr->next; // Link newNode with next node
        if(curr->next != NULL){
            curr->next->prev = newNode;  // Link next node back to newNode
        }
        curr->next = newNode;   // Link previous node to newNode
    }

    temp = head;
    cout << "Updated List: ";
    while(temp != NULL){
        cout << temp->data;
        if(temp->next != NULL) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
    return 0; 
}