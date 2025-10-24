// Delete Node by Position.

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        this->data = x;
        this->next = NULL;
    }
};

Node* deleteAtPos(Node* head, int position){
    Node* temp = head;

    if(position == 1){
        head = temp->next;
        delete temp;
        return head;
    }

    Node* prev = head;
    for(int i = 0; i < position; i++){
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;

    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;

    int position = 3;
    head = deleteAtPos(head, position);

    curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;

    return 0; 
}