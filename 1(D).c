#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}


int isEmpty(struct Stack* s) {
    return s->top == -1;
}


int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;  
    }
    return s->arr[(s->top)--];
}

int compareStacks(struct Stack* s1, struct Stack* s2) {
    
    if (s1->top != s2->top) {
        return 0;  
    }

    for (int i = 0; i <= s1->top; i++) {
        if (s1->arr[i] != s2->arr[i]) {
            return 0;  
        }
    }

    return 1; 
}

int main() {
    struct Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    int n1, n2;
    
    printf("Enter number of elements for the first stack: ");
    scanf("%d", &n1);
    printf("Enter elements for the first stack: ");
    for (int i = 0; i < n1; i++) {
        int value;
        scanf("%d", &value);
        push(&stack1, value);
    }

    
    printf("Enter number of elements for the second stack: ");
    scanf("%d", &n2);
    printf("Enter elements for the second stack: ");
    for (int i = 0; i < n2; i++) {
        int value;
        scanf("%d", &value);
        push(&stack2, value);
    }

   
    if (compareStacks(&stack1, &stack2)) {
        printf("The stacks are equal.\n");
    } else {
        printf("The stacks are not equal.\n");
    }

    return 0;
}
