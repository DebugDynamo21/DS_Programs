#include <stdio.h>
#include <stdlib.h>

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
        printf("Memory allocation failed\n");
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
    printf("%d inserted with priority %d\n", val, pr);
}

void delete(){
    if(front == NULL){
        printf("Queue is empty!.");
        return;
    }
    struct Node* temp = front;
    printf("%d Deleted with priority %d\n", temp->data, temp->priority);

    front = front->next;
    free(temp);
}

void display(){
    if(front == NULL){
        printf("Queue is empty!\n");
        return;
    }
    printf("Priority Queue:\n");
    printf("(value, priority)\n");

    struct Node* temp = front;
    while(temp != NULL){
        printf("%d %d", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice, value, pr;

    while (1) {
        printf("\n--- PRIORITY QUEUE USING LINKED LIST (DMA) ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter priority (lower value = higher priority): ");
                scanf("%d", &pr);
                insert(value, pr);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0; 
}