// Traversal of Singly Linked List (Iterative Approach).

// The process of traversing a singly linked list involves printing the value of each node 
// and then going on to the next node and print that node's value also and so on, till we 
// reach the last node in the singly linked list, whose next node points towards the null.

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int new_node){
            data = new_node;
            this->next = NULL;
        }
};

//function to traverse and print the singly linked list.
void traverseList(Node* start){
    // start is the head node of the linked list.
    while(start != NULL){
        cout << start->data << " ";
        if(start->next != NULL){
            cout << "-> ";
        }   // to avoid printing arrow after last node
        start = start->next;
    }
    cout << endl;
}

int main(){
    // create a hard-coded linked list:
    // 10 -> 20 -> 30 -> 40

    Node* start = new Node(10); // head node
    start->next = new Node(20); // second node
    start->next->next = new Node(30);   // third node
    start->next->next->next = new Node(40); // fourth node

    traverseList(start);
}