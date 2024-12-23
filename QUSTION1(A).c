#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define a structure for the stack
struct Stack {
    int items[MAX];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1; // Set top to -1 to indicate the stack is empty
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full!\n");
        return;
    }
    stack->items[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1; 
    }
    return stack->items[stack->top--];
}


void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Reversed list: ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));  
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    int n, value;

    initializeStack(&stack);

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&stack, value);
    }

    
    displayStack(&stack);

    return 0;
}
