#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Define the deque structure
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the deque
void initializeDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return deque->front == NULL;
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque* deque, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = deque->front;
    newNode->prev = NULL;

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
        deque->front = newNode;
    }

    printf("Inserted %d at the front.\n", value);
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque* deque, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }

    printf("Inserted %d at the rear.\n", value);
}

// Function to delete an element from the front of the deque
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty! No element to delete from the front.\n");
        return;
    }

    struct Node* temp = deque->front;
    deque->front = deque->front->next;

    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }

    printf("Deleted %d from the front.\n", temp->data);
    free(temp);
}

// Function to delete an element from the rear of the deque
void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty! No element to delete from the rear.\n");
        return;
    }

    struct Node* temp = deque->rear;
    deque->rear = deque->rear->prev;

    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }

    printf("Deleted %d from the rear.\n", temp->data);
    free(temp);
}

// Function to display the elements of the deque from front to rear
void displayDeque(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    struct Node* temp = deque->front;
    printf("Deque contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Deque deque;
    initializeDeque(&deque);

    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert at front
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&deque, value);
                break;

            case 2: // Insert at rear
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&deque, value);
                break;

            case 3: // Delete from front
                deleteFront(&deque);
                break;

            case 4: // Delete from rear
                deleteRear(&deque);
                break;

            case 5: // Display deque
                displayDeque(&deque);
                break;

            case 6: // Exit
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
