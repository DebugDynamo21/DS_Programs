// Write a cpp program to implement primitive operation on double ended queue.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node* frontPtr = nullptr;
Node* rearPtr = nullptr;

void insertFront(int val) {
    Node* newNode = new Node(val);

    if (frontPtr == nullptr) {
        frontPtr = rearPtr = newNode;
    } else {
        newNode->next = frontPtr;
        frontPtr->prev = newNode;
        frontPtr = newNode;
    }
    cout << "Inserted " << val << " at front\n";
}

void insertRear(int val) {
    Node* newNode = new Node(val);

    if (rearPtr == nullptr) {
        frontPtr = rearPtr = newNode;   // FIXED your original bug!
    } else {
        rearPtr->next = newNode;
        newNode->prev = rearPtr;
        rearPtr = newNode;
    }
    cout << "Inserted " << val << " at rear\n";
}

void deleteFront() {
    if (frontPtr == nullptr) {
        cout << "Queue is empty!\n";
        return;
    }

    Node* temp = frontPtr;
    cout << "Deleted " << temp->data << " from front\n";

    if (frontPtr == rearPtr) {
        frontPtr = rearPtr = nullptr;
    } else {
        frontPtr = frontPtr->next;
        frontPtr->prev = nullptr;
    }
    delete temp;
}

void deleteRear() {
    if (rearPtr == nullptr) {
        cout << "Queue is empty!\n";
        return;
    }

    Node* temp = rearPtr;
    cout << "Deleted " << temp->data << " from rear\n";

    if (frontPtr == rearPtr) {
        frontPtr = rearPtr = nullptr;
    } else {
        rearPtr = rearPtr->prev;
        rearPtr->next = nullptr;
    }
    delete temp;
}

void display() {
    if (frontPtr == nullptr) {
        cout << "Deque is empty.\n";
        return;
    }

    Node* temp = frontPtr;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n--- DEQUE OPERATIONS USING DMA (C++) ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertFront(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
