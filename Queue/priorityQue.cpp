// Implementation of Priority queue using an array in which elements are inserted 
// with a value and a priority.

#include <iostream>
using namespace std;

struct Node{
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

struct Node* createNode(int val, int pr){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode){
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }
    newNode->data = val;
    newNode->priority = pr;
    newNode->next = NULL;
    return newNode;
}

void insert(int val, int pr){
    struct Node* newNode = createNode(val, pr);
    
    if(front == NULL || pr < front->priority){
        newNode->next = front;
        front = newNode;
    }else{
        struct Node* temp = front;
        while(temp->next != NULL || temp->next->priority <= pr){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    cout << val << " inserted with priority " << pr << endl;
}

void deleteNode(){
    if(front == NULL){
        cout << "Queue is empty!" << endl;
        return;
    }
    struct Node* temp = front;
    cout << "Deleted element: " << temp->data << " with priority " << temp->priority << endl;

    front = front->next;
    free(temp);
}

void display(){
    if(front == NULL){
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Priority Queue: ";
    cout << "Data | Priority" << endl;
    cout << "----------------" << endl;

    struct Node* temp = front;
    while(temp != NULL){
        cout << temp->data << " " << temp->priority << endl;
        temp = temp->next;
    }
    cout << "----------------" << endl;
}

int main(){
    int choice, value, pr;

    while (1) {
        cout << "Priority Queue Operations:" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Display queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value and priority: ";
                cin >> value >> pr;
                insert(value, pr);
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                exit(0);

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
    return 0; 
}