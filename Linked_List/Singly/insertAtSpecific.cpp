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

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    Node* curr = head;
    cout << "Original Linked list: ";
    while(curr != NULL){
        cout << curr->data;
        if(curr->next != NULL) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    int pos = 4, val = 40;

    if(pos == 1){   // insert at head
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }else{      
        //Traverse to the node that will be present just before the new node.
        Node* temp = head;
        for(int i = 1; i < pos - 1 && temp != NULL; i++){
            temp = temp->next;
        }

        if(temp != NULL){
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    cout << "List after insertion: ";
    curr = head;
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    free(curr);
    return 0; 
}