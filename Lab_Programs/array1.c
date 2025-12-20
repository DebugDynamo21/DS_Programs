// Array Insertion, Deletion, Traversal.

#include <stdio.h>

#define MAX_SIZE 100

void traverseArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertElement(int arr[], int size) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return size;
    }

    int element, position;

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    printf("Enter the position (1 to %d): ", size + 1);
    scanf("%d", &position);

    if (position < 1 || position > size + 1) {
        printf("Invalid position.\n");
        return size;
    }

    int index = position - 1;

    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }

    arr[index] = element;
    printf("Element %d inserted successfully.\n", element);

    return size + 1;
}

int deleteElement(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return size;
    }

    int position;

    printf("Enter the position to delete (1 to %d): ", size);
    scanf("%d", &position);

    if (position < 1 || position > size) {
        printf("Invalid position.\n");
        return size;
    }

    int index = position - 1;
    int deletedElement = arr[index];

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    printf("Element %d deleted successfully.\n", deletedElement);
    
    return size - 1;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Traverse Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                size = insertElement(arr, size);
                break;
            case 2:
                size = deleteElement(arr, size);
                break;
            case 3:
                traverseArray(arr, size);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}