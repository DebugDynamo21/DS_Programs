// Insert a node at the end of the linked list using functions.

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

Node* insertAtEnd(Node* head, int x){
    Node* new_node = new Node(x);

    if(head == NULL){
        return new_node;
    }

    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    ptr->next = new_node;

    return head;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int new_node = 50;
    insertAtEnd(head, new_node);

    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    free(temp);
    cout << endl;
    return 0; 
}