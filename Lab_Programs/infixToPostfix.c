#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow.\n");
        exit(1);
    }
    top++;
    stack[top] = value;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow.\n");
        exit(1);
    }
    char value = stack[top];
    top--;
    return value;
}

int isEmpty() {
    return top == -1;
}

char peek() {
    if (top == -1) {
        return '\0';
    }
    return stack[top];
}

int isOperand(char ch) {
    return isalnum(ch);
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    int i, j;

    printf("Enter an infix expression (e.g., a+b*c-d/e): ");
    scanf("%s", infix);

    j = 0;
    for (i = 0; i < strlen(infix); i++) {
        char symbol = infix[i];

        if (isOperand(symbol)) {
            postfix[j++] = symbol;
        }
        else if (symbol == '(') {
            push(symbol);
        }
        else if (symbol == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty() && peek() == '(') {
                pop();
            }
        }
        else {
            while (!isEmpty() && precedence(peek()) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
