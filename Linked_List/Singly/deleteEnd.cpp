// Deletion at end (Removal of last node) in a Linked List.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";  // Print Original List (without destroying head)
    Node* curr = head;
    while(curr != NULL){
        cout << curr->data;
        if(curr->next != NULL) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    if(head == NULL){   // Deletion at end
        cout << "List is empty!";
    }
    else if(head->next == head){    // If only one node is present
        cout << head->data;
        delete head;
        head = NULL;
    }else{
        Node* secondLast = head;    // Find the second last node
        while(secondLast->next->next != NULL){
            secondLast = secondLast->next;
        }
        delete secondLast->next;    // Delete the last node

        secondLast->next = NULL;    // Change next of second last
    }

    cout << "List after deletion of last node: ";
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data;
        if(temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;

    return 0; 
}