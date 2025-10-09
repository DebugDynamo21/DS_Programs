// Implement primitive operations of stack using array.

#include <iostream>
using namespace std;

class myStack{  // stack class
    int *arr;
    int capacity;
    int top;

    public:
        myStack(int cap){   // constructor
            capacity = cap;
            arr = new int[capacity];
            top = -1;
        }

        void push(int x){   // push operation
            if(top == capacity - 1){    // stack overflow condition
                cout << "Stack Overflow\n";
                return;
            }
            arr[++top] = x; // increment top and add element
        }

        int pop(){  // pop operation
            if(top == -1){
                cout << "Stack Underflow\n";    // stack underflow condition
                return -1;
            }
            return arr[top--];  // return top element and decrement top
        }

        int peek(){ // peek operation
            if(top == -1){
                cout << "Stack is empty\n";
                return -1;
            }
            return arr[top];    // return top element
        }

        bool isEmpty(){ // check if stack is empty
            return top == -1;
        }

        bool isFull(){  // check if stack is full
            return top = capacity - 1;
        }
};

int main(){
    myStack st(5);  // create stack of capacity 5

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Popped value: " << st.pop() << endl;
    cout << "Top element: " << st.peek() << endl;
    cout << "Stack size: " << sizeof(myStack) / sizeof(int) << endl;
    cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full: " << (st.isFull() ? "Yes" : "No") << endl;
    
    return 0; 
}