// Traversal of Singly Linked List (Recursive Approach)

// We can also traverse the singly linked list using recursion. We start at the head node 
// of the singly linked list, check if it is null or not and print its value. We then call 
// the traversal function again with the next node passed as pointer.

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        //constructor to initialize new node with data.
        Node (int new_node){
            this->data = new_node;
            this->next = NULL;
        }
};

// function to traverse and print the singly linked list(recursively).
void traversalList(Node* start){
    // base case when start is null pointer.
    if(start == NULL){
        cout << endl;
        return; 
    }

    //printing the current node data.
    cout << start->data << " ";

    //print arrow if not the last node in the list.
    if(start->next != NULL){
        cout << "-> ";
    }

    //moving to the next node recursively.
    traversalList(start->next);
}

int main(){
    Node* start = new Node(10);
    start->next = new Node(20);
    start->next->next = new Node(30);
    start->next->next->next = new Node(40);

    traversalList(start);
}