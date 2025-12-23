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

void insertAtBeginning() {
    int data;
    printf("Enter data to insert at beginning: ");
    scanf("%d", &data);
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning.\n", data);
}

void insertAtEnd() {
    int data;
    printf("Enter data to insert at end: ");
    scanf("%d", &data);
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        printf("%d inserted at the end.\n", data);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("%d inserted at the end.\n", data);
}

void insertAtPosition() {
    int data, pos, i;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    printf("Enter position (1-based index): ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        struct Node* newNode = createNode(data);
        newNode->next = head;
        head = newNode;
        printf("%d inserted at position %d.\n", data, pos);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position. Position out of bounds.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("%d inserted at position %d.\n", data, pos);
    }
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    int deletedData = temp->data;
    head = head->next;
    free(temp);
    printf("%d deleted from the beginning.\n", deletedData);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (head->next == NULL) {
        int deletedData = head->data;
        free(head);
        head = NULL;
        printf("%d deleted from the end.\n", deletedData);
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    int deletedData = temp->data;
    prev->next = NULL;
    free(temp);
    printf("%d deleted from the end.\n", deletedData);
}

void deleteByValue() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    
    int data;
    printf("Enter data to delete: ");
    scanf("%d", &data);

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        printf("%d deleted from the list.\n", data);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the list.\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the list.\n", data);
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

int main() {
    int choice;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete by Value\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtPosition();
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                deleteByValue();
                break;
            case 7:
                displayList();
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }
    }

    return 0;
}
