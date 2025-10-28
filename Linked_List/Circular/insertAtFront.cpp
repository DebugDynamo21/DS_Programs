// Write a cpp program to insert a node at the beginning of a circular linked list.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* insertAtFront(Node* last, int key){
    Node* newNode = new Node(key);

    if(last == NULL){
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = last->next;
    last->next = newNode;
    return last;
}

void printList(Node* last) {
    if (last == nullptr) return;

    Node* head = last->next;
    Node* temp = head;

    do {
        cout << temp->data;
        temp = temp->next;
        if (temp != head) cout << " -> ";
    } while (temp != head);

    cout << endl;
}

int main() {
    // Create circular linked list: 2 -> 3 -> 4
    Node* first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);

    Node* last = first->next->next;
    last->next = first;

    cout << "Original List: ";
    printList(last);

    // Insert 1 at the beginning
    last = insertAtFront(last, 1);

    cout << "After insertion: ";
    printList(last);

    return 0;
}