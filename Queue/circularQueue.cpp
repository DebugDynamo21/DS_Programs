// Write a cpp program to implement primitive operations on a circular queue.

#include <iostream>
using namespace std;

class myQueue{
    public:
        int* arr;
        int front;
        int size;
        int capacity;

        myQueue(int cap){
            capacity = cap;
            arr = new int[capacity];
            front = 0;
            size = 0;
        }

        void enqueue(int x){
            if(size == capacity){
                cout << "Queue is full\n";
            }
            int rear = (front + size) % capacity;
            arr[rear] = x;
            size++;
        }

        int dequeue(){
            if(size == 0){
                cout << "Queue is empty\n";
                return -1;
            }
            int res = arr[front];
            front = (front + 1) % capacity;
            size--;
            return res;
        }

        int getFront(){
            if (size == 0){
                return -1;
            }
            return arr[front];
        }

        int getRear(){
            if(size == 0){
                return -1;
            }
            int rear = (front + size -1) % capacity;
            return arr[rear];
        }
};

int main(){
    myQueue q(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    for(int i = 0; i < q.size; i++){
        cout << q.arr[i] << " ";
    }
    cout << endl;

    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
    return 0; 
}