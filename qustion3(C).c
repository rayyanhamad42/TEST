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

void removeDuplicates(struct Node* head) {
    struct Node* current = head;


    while (current != NULL && current->next != NULL) {
       
        if (current->data == current->next->data) {
            struct Node* temp = current->next; 
            current->next = current->next->next;  
            free(temp);  
        } else {
            current = current->next; 
        }
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
    int value, choice;

    printf("Enter values for the sorted list (enter 0 to stop):\n");
    while (1) {
        printf("Enter value: ");
        scanf("%d", &value);
        if (value == 0) break;
        insertNode(&head, value);
    }

   
    printf("Original List:\n");
    displayList(head);

    
    removeDuplicates(head);

    printf("List after removing duplicates:\n");
    displayList(head);

    freeList(head);

    return 0;
}
