// Insert a new node at the end of a linked list.

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int new_node){
        data = new_node;
        next = NULL;
    }
};

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    Node* new_node = new Node(50);

//Check if the linked list is empty.
    if(head == NULL){
        cout << "Linked list is empty" << endl;
    }

    Node* ptr = head;   // Store the head reference in a temporary variable
    
    while(ptr->next != NULL){
        // Traverse till the last node
        ptr = ptr->next;
    }
// Change the next pointer of the last node to point to the new node
    ptr->next = new_node;

    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return 0; 
}