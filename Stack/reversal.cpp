// Reversal of Singly linked list.

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void reverse(Node** head){
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while(current != NULL){
        next = current->next;   // Store next node
        current->next = prev;   // Reverse current node's pointer
        prev = current;         // Move pointers one position ahead.
        current = next;
    }
    *head = prev;               // Update head to new first node
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void push(Node** head, int new_data){
    Node* new_node = new Node(new_data);
    new_node->next = (*head);
    (*head) = new_node;
}

int main(){
    Node* head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);

    cout << "Given linked list: ";
    display(head);

    reverse(&head);

    cout << "Reversed linked list: ";
    display(head);
    return 0; 
}