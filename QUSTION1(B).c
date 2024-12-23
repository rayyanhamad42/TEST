#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    char items[MAX];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1; 
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


void push(struct Stack* stack, char value) {
    if (stack->top == MAX - 1) {
        printf("Stack is full!\n");
        return;
    }
    stack->items[++stack->top] = value;
}


char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1; 
    }
    return stack->items[stack->top--];
}


int checkNesting(char* expression) {
    struct Stack stack;
    initializeStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

      
        if (ch == '(') {
            push(&stack, ch);
        }

        else if (ch == ')') {
            if (isEmpty(&stack)) {
                return 0;
            } else {
                pop(&stack);
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    char expression[MAX];

  
    printf("Enter an expression with parentheses: ");
    fgets(expression, MAX, stdin);  

    if (checkNesting(expression)) {
        printf("Parentheses are properly nested.\n");
    } else {
        printf("Parentheses are not properly nested.\n");
    }

    return 0;
}
