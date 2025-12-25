#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow. Expression is too long.\n");
        exit(1); 
    }
    top++;
    stack[top] = value;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    char value = stack[top];
    top--;
    return value;
}

int isEmpty() {
    return top == -1;
}

int main() {
    char expression[MAX_SIZE];
    int i;
    int isBalanced = 1;

    printf("Enter an expression with parentheses (e.g., {a+[b*(c-d)]}): ");
    scanf("%s", expression);

    for (i = 0; i < strlen(expression); i++) {
        char symbol = expression[i];

        if (symbol == '(' || symbol == '{' || symbol == '[') {
            push(symbol);
        }
        else if (symbol == ')' || symbol == '}' || symbol == ']') {
            if (isEmpty()) {
                isBalanced = 0;
                break;
            }

            char topChar = pop();

            if (symbol == ')' && topChar != '(') {
                isBalanced = 0;
                break;
            }
            if (symbol == '}' && topChar != '{') {
                isBalanced = 0;
                break;
            }
            if (symbol == ']' && topChar != '[') {
                isBalanced = 0;
                break;
            }
        }
    }

    if (!isEmpty()) {
        isBalanced = 0;
    }

    if (isBalanced) {
        printf("The expression has balanced parentheses.\n");
    } else {
        printf("The expression does NOT have balanced parentheses.\n");
    }

    return 0;
}
