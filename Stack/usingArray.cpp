// Implement primitive operations of stack using array.

#include <iostream>
using namespace std;

class myStack{
    int *arr;
    int capacity;
    int top;

    public:
        myStack(int cap){
            capacity = cap;
            arr = new int[capacity];
            top = -1;
        }

        void push(int x){
            if(top == capacity - 1){
                cout << "Stack Overflow\n";
                return;
            }
            arr[++top] = x;
        }

        int pop(){
            if(top == -1){
                cout << "Stack Underflow\n";
                return -1;
            }
            return arr[top--];
        }

        int peek(){
            if(top == -1){
                cout << "Stack is empty\n";
                return -1;
            }
            return arr[top];
        }

        bool isEmpty(){
            return top == -1;
        }

        bool isFull(){
            return top = capacity - 1;
        }
};

int main(){
    myStack st(5);

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