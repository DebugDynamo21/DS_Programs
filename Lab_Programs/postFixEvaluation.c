#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow. Expression may be invalid.\n");
        exit(1);
    }
    top++;
    stack[top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow. Expression may be invalid.\n");
        exit(1);
    }
    int value = stack[top];
    top--;
    return value;
}

int main() {
    char postfix[MAX_SIZE];
    int i, op1, op2, result;

    printf("Enter a postfix expression (e.g., 23*5+): ");
    scanf("%s", postfix);

    for (i = 0; i < strlen(postfix); i++) {
        char symbol = postfix[i];

        if (isdigit(symbol)) {
            push(symbol - '0');
        }
        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
            
            op2 = pop();
            op1 = pop();

            switch (symbol) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("Error: Division by zero.\n");
                        exit(1);
                    }
                    result = op1 / op2;
                    break;
            }
            
            push(result);
        }
    }

    if (top == 0) {
        printf("Result of postfix evaluation: %d\n", stack[top]);
    } else {
        printf("Error: Invalid postfix expression.\n");
    }

    return 0;
}
