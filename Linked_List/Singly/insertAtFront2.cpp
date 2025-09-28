// Insert a new node at the front of a linked list using function.

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* insertAtFront(Node* head, int x){
    Node* new_node = new Node(x);
    new_node->next = head;    // Link the new node to the previous head
    head = new_node;    // Update head to point to the new node

    return head;
}

int main(){
    Node* head = new Node(20);
    head->next = new Node(30);
    head->next->next = new Node(40);
    head->next->next->next = new Node(50);

    int x = 10;
    head = insertAtFront(head, x);
    
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    return 0; 
}