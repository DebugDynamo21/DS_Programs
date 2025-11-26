// Linear Queue implementation in C++ using linked list.

#include <iostream>
using namespace std;

// Node structure definition
struct Node {
    int data;
    Node* next;

    // Constructor to easily create a new node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Class to handle Queue operations
class Queue {
private:
    Node *front;
    Node *rear;

public:
    // Constructor to initialize front and rear
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to enqueue an element
    void enqueue(int val) {
        // 'new' is the C++ equivalent of malloc
        Node* newNode = new Node(val); 

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << val << " to queue." << endl;
    }

    // Function to dequeue an element
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeued " << front->data << " from queue." << endl;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        // 'delete' is the C++ equivalent of free
        delete temp; 
    }

    // Function to display the queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Destructor to clean up memory when program exits (Good C++ practice)
    ~Queue() {
        while(front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q; // Create an object of the Queue class
    int choice, val;

    while (true) {
        cout << "\n* * * * Linear Queue Operations * * * *" << endl;
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}