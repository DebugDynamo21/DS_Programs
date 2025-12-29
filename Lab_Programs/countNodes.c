#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);
    struct Node* fourth = createNode(40);

    head->next = second;
    second->next = third;
    third->next = fourth;

    printf("Linked List: %d -> %d -> %d -> %d -> NULL\n", head->data, second->data, third->data, fourth->data);

    int totalNodes = countNodes(head);

    printf("Total number of nodes: %d\n", totalNodes);

    free(head);
    free(second);
    free(third);

    return 0;
}
