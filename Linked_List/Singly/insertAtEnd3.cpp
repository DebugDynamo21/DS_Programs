// Insert a node at the end of a linked list. Take input from user.

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

Node* insertAtEnd(Node* head, int val){
    Node* newNode = new Node(val);
    Node* temp = head;

    while(temp->next != NULL){  // Traverse to the last node
        temp = temp->next;      // Move to the next node
    }
    temp->next = newNode;       // Link the last node to the new node
    
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
    
    Node* head = new Node(x);
    Node* curr = head;

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

    head = insertAtEnd(head, val);

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