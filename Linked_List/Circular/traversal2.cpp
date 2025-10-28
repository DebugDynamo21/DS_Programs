// Write a cpp program to implement traversal on circular singly linked list.
// RECURSIVE APPROACH.

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node (int newNode){
            data = newNode;
            next = NULL;
        }
};

void printList(Node* curr, Node* head){
    if(head == NULL){
        return;
    }

    if(curr->next == head){
        return;
    }

    printList(curr->next, head);
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(2);
    head->next->next = new Node(16);
    head->next->next->next = new Node(12);

    head->next->next->next->next = head;

    printList(head, head);
    return 0; 
}