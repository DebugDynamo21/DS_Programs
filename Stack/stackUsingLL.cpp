// Implement stack using linked list.

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node (int x){
        data = x;
        next = NULL;
    }
};

Node* top = NULL;  // Global top pointer
void push(int x){
    Node* temp = new Node(x);
    if(!temp){
        cout << "Stack Overflow" << endl;
        return;
    }
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop(){
    Node* temp;
    if(top == NULL){
        cout << "Stack Underflow" << endl;
        return;
    }
    temp = top;
    top = top->next;
    free(temp);
}

void display(){
    Node* temp;
    if(top == NULL){
        cout << "Stack is empty" << endl;
        return;
    }
    else{
        temp = top;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}

int main(){
    // Testing the stack implementation
    push(10);
    push(20);
    push(30);

    cout << "Stack elements: ";
    display();
    pop();
    cout << "Stack elements after pop: ";
    display();

    return 0; 
}