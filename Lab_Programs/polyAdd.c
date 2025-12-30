#include <stdio.h>
#include <stdlib.h>

struct Node {
    float coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(float coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertTerm(struct Node* head, float coeff, int exp) {
    if (coeff == 0) return head;

    struct Node* newNode = createNode(coeff, exp);
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (head == NULL || exp > head->exp) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    while (temp != NULL && temp->exp > exp) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL && temp->exp == exp) {
        temp->coeff += coeff;
        if (temp->coeff == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
        }
        free(newNode); 
    } else {
        newNode->next = temp;
        if (prev != NULL) {
            prev->next = newNode;
        }
    }
    return head;
}

struct Node* createPolynomial() {
    struct Node* head = NULL;
    int n, i, exp;
    float coeff;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &exp);
        head = insertTerm(head, coeff, exp);
    }
    return head;
}

void displayPolynomial(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("0\n");
        return;
    }
    while (temp != NULL) {
        printf("(%.1fx^%d)", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            result = insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            result = insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            float sum = p1->coeff + p2->coeff;
            result = insertTerm(result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    int choice;

    while (1) {
        printf("\n--- Polynomial Arithmetic Menu ---\n");
        printf("1. Enter Polynomial 1\n");
        printf("2. Enter Polynomial 2\n");
        printf("3. Add Polynomials\n");
        printf("4. Display Polynomial 1\n");
        printf("5. Display Polynomial 2\n");
        printf("6. Display Sum\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                freeList(poly1);
                printf("Enter details for Polynomial 1:\n");
                poly1 = createPolynomial();
                break;
            case 2:
                freeList(poly2);
                printf("Enter details for Polynomial 2:\n");
                poly2 = createPolynomial();
                break;
            case 3:
                freeList(sum);
                sum = addPolynomials(poly1, poly2);
                printf("Polynomials added successfully.\n");
                break;
            case 4:
                printf("Polynomial 1: ");
                displayPolynomial(poly1);
                break;
            case 5:
                printf("Polynomial 2: ");
                displayPolynomial(poly2);
                break;
            case 6:
                printf("Sum: ");
                displayPolynomial(sum);
                break;
            case 7:
                freeList(poly1);
                freeList(poly2);
                freeList(sum);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
