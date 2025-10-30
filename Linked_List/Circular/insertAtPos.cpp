// Write a cpp Program to insert a node at a specific position in a circular linked list.

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

// Function to insert a node at a specific position in a circular linked list.
Node* insertAtPos(Node* last, int value, int pos){
    if(last == NULL){
        // If the list is empty
        if(pos != 1){
            cout << "The position does not exist in an empty list." << endl;
            return last;
        }
        //Create a new node and make it point to itself.
        Node* newNode = new Node(value);
        last = newNode;
        last->next = last;
        return last;
    }

    // Create a new node with the given value
    Node *newNode = new Node(value);

    // curr will point to head initially.
    Node* curr = last->next;

    if (pos == 1){
        // Insert at beginning
        newNode->next = curr;
        last->next = newNode;
        return last;
    }

    // Traverse the list to find the insertion point.
    for(int i = 1; i < pos - 1; i++){
        curr = curr->next;

        //If position is out of bounds
        if(curr == last->next){
            cout << "Invalid Position!" << endl;
            return last;
        }
    }

    // Insert new node at the desired position
    newNode->next = curr->next;
    curr->next = newNode;

    // Update last if the new node is inserted at the end.
    if(curr == last){
        last = newNode;
    }
    return last;
}

void printList(Node* last){
    if (last == NULL) {
        return;
    }
    Node* head = last->next;
    while(true){
        cout << head->data << " ";
        head = head->next;
        if(head == last->next){
            break;
        }
    }
    cout << endl;
}

int main(){
    Node* first = new Node(3);
    first->next = new Node(5);
    first->next->next = new Node(6);
    
    Node* last = first->next->next;
    last->next = first;

    cout << "Original List: ";
    printList(last);

    int data = 4, position = 2;
    insertAtPos(last, data, position);
    insertAtPos(last, 2, 1);

    cout << "List after insertion: ";
    printList(last);
    return 0; 
}