// Insert a node at beginning in a linked list. Take input from user.

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node (int new_node){
        data = new_node;
        next = NULL;
    }
};

Node* insertAtFront(Node* head, int val){
    Node* newNode = new Node(val);  // Create a new node with the given value
    newNode->next = head;   // Point the new node's next to the current head
    head = newNode;         // Update head to the new node
    
    return head;
}

int main(){
    int n;
    cout << "Enter number of nodes in initial linked list: ";
    cin >> n;

    if(n <= 0){
        cout << "List cannot be empty!" << endl;
        return 0;
    }

    cout << "Enter " << n << " values: ";
    int x;
    cin >> x;
    
    Node* head = new Node(x);   // Create the head node
    Node* curr = head;          // Pointer to traverse the list

    for(int i = 2; i <= n; i++){
        cin >> x;
        curr->next = new Node(x);
        curr = curr->next;
    }

    cout << "Original list: ";
    curr = head;
    while(curr != NULL){
        cout << curr->data;
        if(curr->next != NULL) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    int val;
    cout << "Enter value to insert: ";
    cin >> val;

    head = insertAtFront(head, val);

    cout << "List after insertion: ";
    curr = head;
    while(curr != NULL){
        cout << curr->data;
        if(curr->next != NULL) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
    return 0; 
}