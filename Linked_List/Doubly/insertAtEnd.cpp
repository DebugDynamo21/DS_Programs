// Insert a Node at the end of Doubly Linked List.

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next, *prev;

    Node (int new_node){
        data = new_node;
        next = prev = NULL;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev= head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    Node* curr = head;

    cout << "Original List: ";
    while(curr != NULL){
        cout << curr->data;
        if(curr->next != NULL) cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;

    Node* newNode = new Node(4);
    
    if(head == NULL){
        head = newNode;  // If list is empty, newNode becomes the head
    }else{
        Node* temp = head;  // Traverse to the end of the list
        while(temp->next != NULL){
            temp = temp->next;  // Move to next node
        }
        temp->next = newNode;   // Link the last node to newNode
        newNode->prev = temp;   // Link newNode back to the last node
    }

    cout << "Updated List: ";
    curr = head;
    while(curr != NULL){
        cout << curr->data;
        if(curr->next != NULL) cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;
    return 0; 
}