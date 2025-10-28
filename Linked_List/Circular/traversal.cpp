// Write a cpp program to traverse circular singly linked list.
//ITERATIVE APPROACH

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

void printList(Node* head){
    if(head == NULL){
        return;
    }

    Node* curr = head;
    do{
        cout << curr->data << " ";
        curr = curr->next;
    }while(curr != head);
    cout << endl;
    return;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(2);
    head->next->next = new Node(16);
    head->next->next->next = new Node(12);

    head->next->next->next->next = head;

    printList(head);
    return 0; 
}