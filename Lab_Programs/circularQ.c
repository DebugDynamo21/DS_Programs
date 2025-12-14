#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1, capacity;

int isFull() {
    return ((rear + 1) % capacity == front);
}

int isEmptyQueue() {
    return (front == -1);
}

void enqueue() {
    int value;
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % capacity;

    queue[rear] = value;
    printf("%d enqueued successfully\n", value);
}

void dequeue() {
    if (isEmptyQueue()) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % capacity;
}

void getFront() {
    if (isEmptyQueue())
        printf("Queue is empty\n");
    else
        printf("Front element: %d\n", queue[front]);
}

void getRear() {
    if (isEmptyQueue())
        printf("Queue is empty\n");
    else
        printf("Rear element: %d\n", queue[rear]);
}

void isEmpty() {
    if (isEmptyQueue())
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}

void getSize() {
    if (isEmptyQueue())
        printf("Current size: 0\n");
    else if (rear >= front)
        printf("Current size: %d\n", rear - front + 1);
    else
        printf("Current size: %d\n", capacity - front + rear + 1);
}

void display() {
    if (isEmptyQueue()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % capacity;
    }
    printf("\n");
}

int main() {
    int choice;
    printf("Enter queue capacity: ");
    scanf("%d", &capacity);

    if (capacity <= 0) {
        printf("Invalid capacity. Must be greater than 0.\n");
        return 1;
    }
    queue = (int*)malloc(capacity * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Get Front\n4. Get Rear\n5. Is Empty\n6. Size\n7. Display\n8. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: getFront(); break;
            case 4: getRear(); break;
            case 5: isEmpty(); break;
            case 6: getSize(); break;
            case 7: display(); break;
            case 8: free(queue); exit(0);
            default: printf("Invalid choice\n");
        }
    }
}