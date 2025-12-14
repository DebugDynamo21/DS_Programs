#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1, capacity;

void enqueue() {
    int value;
    if (rear == capacity - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        printf("Enter value: ");
        scanf("%d", &value);
        queue[++rear] = value;
        printf("%d enqueued successfully\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue Underflow\n");
    else {
        printf("Deleted: %d\n", queue[front++]);
        if (front > rear) front = rear = -1;
    }
}

void getFront() {
    if (front == -1)
        printf("Queue is empty\n");
    else
        printf("Front element: %d\n", queue[front]);
}

void getRear() {
    if (rear == -1)
        printf("Queue is empty\n");
    else
        printf("Rear element: %d\n", queue[rear]);
}

void isEmpty() {
    if (front == -1)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}

void getSize() {
    if (front == -1)
        printf("Current size: 0\n");
    else
        printf("Current size: %d\n", rear - front + 1);
}

void display() {
    if (front == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    printf("Enter queue capacity: ");
    scanf("%d", &capacity);
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
