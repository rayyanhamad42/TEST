#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/
void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void removeDuplicates(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;
    struct Node* temp;

    
    while (current != NULL && current->next != NULL) {
        prev = current;
        temp = current->next;

        
        while (temp != NULL) {
            if (current->data == temp->data) {
                prev->next = temp->next;  
                free(temp);  
                temp = prev->next; 
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
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
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Remove Duplicates\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertNode(&head, value);
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                removeDuplicates(&head);
                printf("Duplicates removed.\n");
                break;

            case 4:
                freeList(head);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
