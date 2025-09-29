// Creating a Doubly Linked List with 4 Nodes.

#include <iostream>
using namespace std;

class Node{
    public:
    int data;       // To store the data.
    Node* next;     // Pointer to point next node.
    Node* prev;     // Pointer to point prev node.

    Node(int x){    // Constructor
        data = x;
        next = NULL;
        prev = NULL;
    }
};

int main(){
    Node* head = new Node(1);   // Create first node head
    head->next = new Node(2);   // Create second node
    head->next->prev = head;    // Link it to the first node

    head->next->next = new Node(3);     // Third node
    head->next->next->prev = head->next;    // Link it to the second node

    head->next->next->next = new Node(4);   //Fourth node
    head->next->next->next->prev = head->next->next;    // Link it to the third node

    Node* temp = head;      // Temporary pointer for traversal.
    while(temp != NULL){
        cout << temp->data;     // Prints the data in the list.
        if(temp->next != NULL) cout << " <-> ";
        temp = temp->next;      // Moves the pointer to next node.
    }
    cout << endl;
    return 0; 
}

//OUTPUT:
// 1 <-> 2 <-> 3 <-> 4