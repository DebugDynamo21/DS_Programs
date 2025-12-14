#include <stdio.h>
#include <stdlib.h>

int *deque;
int front = -1, rear = -1, capacity;

int isFull() {
    return ((front == 0 && rear == capacity - 1) || (front == rear + 1));
}

int isEmptyQueue() {
    return (front == -1);
}

void insertFront() {
    int value;
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = capacity - 1;
    } else {
        front--;
    }

    deque[front] = value;
    printf("%d inserted at front\n", value);
}

void insertRear() {
    int value;
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1) {
        front = rear = 0;
    } else if (rear == capacity - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
    printf("%d inserted at rear\n", value);
}

void deleteFront() {
    if (isEmptyQueue()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted from front: %d\n", deque[front]);
    if (front == rear)
        front = rear = -1;
    else if (front == capacity - 1)
        front = 0;
    else
        front++;
}

void deleteRear() {
    if (isEmptyQueue()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted from rear: %d\n", deque[rear]);
    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = capacity - 1;
    else
        rear--;
}

void getFront() {
    if (isEmptyQueue())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

void getRear() {
    if (isEmptyQueue())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

void isEmpty() {
    if (isEmptyQueue())
        printf("Deque is empty\n");
    else
        printf("Deque is not empty\n");
}

void getSize() {
    int size;
    if (isEmptyQueue())
        size = 0;
    else if (rear >= front)
        size = rear - front + 1;
    else
        size = capacity - front + rear + 1;
    printf("Current size: %d\n", size);
}

void display() {
    if (isEmptyQueue()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % capacity;
    }
    printf("\n");
}

int main() {
    int choice;
    printf("Enter deque capacity: ");
    scanf("%d", &capacity);

    deque = (int*)malloc(capacity * sizeof(int));
    if (deque == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (1) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Get Front\n6. Get Rear\n7. Is Empty\n8. Size\n9. Display\n10. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertFront(); break;
            case 2: insertRear(); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: getFront(); break;
            case 6: getRear(); break;
            case 7: isEmpty(); break;
            case 8: getSize(); break;
            case 9: display(); break;
            case 10: free(deque); exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
