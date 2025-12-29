#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd() {
    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        printf("%d inserted.\n", data);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("%d inserted.\n", data);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void searchByValue() {
    if (head == NULL) {
        printf("List is empty. Cannot search.\n");
        return;
    }

    int data, pos = 1;
    int found = 0;
    printf("Enter data to search for: ");
    scanf("%d", &data);

    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("%d found at position %d.\n", data, pos);
            found = 1;
        }
        temp = temp->next;
        pos++;
    }

    if (!found) {
        printf("%d not found in the list.\n", data);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert Value\n");
        printf("2. Search for Value\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                insertAtEnd();
                break;
            case 2:
                searchByValue();
                break;
            case 3:
                displayList();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter 1, 2, 3, or 4.\n");
        }
    }

    return 0;
}

