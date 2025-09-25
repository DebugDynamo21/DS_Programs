// Creating an Example Linked List of Size 3 to Understand Working.

#include <iostream>
using namespace std;

//singly linked list node structure
class Node {
    public:
        int data;
        Node* next;

        //constructor to initialize a new node with data
        Node(int new_node){
            data = new_node;
            this->next = NULL;
        }
};

int main(){
    //Create the first node head of the linked list
    Node* head = new Node(10);

    //Create the second node and link it to the head
    head->next = new Node(20);

    //Create the third node and link it to the second node
    head->next->next = new Node(30);

    //Create the fourth node and link it to the third node
    head->next->next->next = new Node(40);

    //printing the linked list
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}
// Output: 
//  10 20 30 40
