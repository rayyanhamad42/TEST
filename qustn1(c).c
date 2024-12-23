#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    char name[50];
    int age;
};

struct Stack {
    struct Student students[MAX];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1; 
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

void push(struct Stack* stack, char name[], int age) {
    if (isFull(stack)) {
        printf("Stack is full! Cannot add more students.\n");
        return;
    }
    stack->top++;
    strcpy(stack->students[stack->top].name, name);
    stack->students[stack->top].age = age;
}
struct Student pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No students to remove.\n");
        struct Student emptyStudent = {"", -1};
        return emptyStudent; 
    }
    return stack->students[stack->top--];
}


void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Student Information (Top to Bottom):\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("Name: %s, Age: %d\n", stack->students[i].name, stack->students[i].age);
    }
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    int choice;
    char name[50];
    int age;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter student's name: ");
                getchar(); 
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;  
                printf("Enter student's age: ");
                scanf("%d", &age);
                push(&stack, name, age);
                break;

            case 2: 
                {
                    struct Student removedStudent = pop(&stack);
                    if (removedStudent.age != -1) {
                        printf("Removed Student - Name: %s, Age: %d\n", removedStudent.name, removedStudent.age);
                    }
                }
                break;

            case 3: 
                displayStack(&stack);
                break;

            case 4: // Exit
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
