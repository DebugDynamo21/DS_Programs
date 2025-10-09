// Write a menu driven c++ program to implement primitive operations on stack using functions.

#include <iostream>
using namespace std;

struct myStack{ // stack structure
    int *arr;
    int capacity;
    int top;

    myStack(int cap){   // constructor
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    void push(int x){   // push operation
        if(top == capacity - 1){
            cout << "Stack Overflow. Stack is full\n";
            return;
        }
        arr[++top] = x; // increment top and add element
        cout << "Pushed value in stack: " << x << endl;
    }

    void pop(){ // pop operation
        if(top == -1){
            cout << "Stack Underflow. Stack is empty\n";
        }else{
            cout << "Popped Value from stack: " << arr[top];
            top--;  // decrement top
        }
    }

    void peek(){    // peek operation
        if(top == -1){
            cout << "Stack is empty!\n";
        }else{
            cout << "Top element: " << arr[top] << endl;
        }
    }

    void display(){ // display stack elements
        if(top == -1){
            cout << "Stack is empty\n";
        }else{
            cout << "Stack elements(top to bottom): \n";
            for(int i = top; i >= 0; i--){
                cout << arr[i] << endl;
            }
            cout << endl;
        }
    }
};

int main(){
    int choice, val;

    myStack st(5);  // create stack of capacity 5

    while(true){
        cout << "\n--------- STACK OPERATIONS MENU ---------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                st.push(val);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.peek();
                break;
            case 4:
                st.display();
                break;
            case 5:
                cout << "Exiting program....\n";
                return 0;
            default:
            cout << "Invalid choice! Try Again! Enter valid choice.\n";
        }
    }

    return 0; 
}