// Insert a new node at the beginning of a linked list.

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int new_node){
        data = new_node;
        next = NULL;
    }
};

int main(){
    Node* start = new Node(20);
    start->next = new Node(30);
    start->next->next = new Node(40);

    Node* new_node = new Node(10);
    new_node->next = start;
    start = new_node;

    Node* ptr = start;
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    free(ptr);
    cout << endl;

    return 0; 
}