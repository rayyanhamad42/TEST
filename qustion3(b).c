#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given value
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
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

// Function to display the linked list
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

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    // If one of the lists is empty, return the other list
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    // Create a new dummy node to help in merging
    struct Node* mergedList = NULL;

    // Initialize the merged list's head
    if (list1->data <= list2->data) {
        mergedList = list1;
        list1 = list1->next;
    } else {
        mergedList = list2;
        list2 = list2->next;
    }

    // Use a temporary node to build the merged list
    struct Node* current = mergedList;

    // Traverse both lists and merge them
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Attach the remaining nodes of list1 or list2
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return mergedList;
}

// Function to free the allocated memory for the list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* mergedList = NULL;

    int value, choice;

    // Insert values into the first list
    printf("Enter values for the first sorted list (enter 0 to stop):\n");
    while (1) {
        printf("Enter value: ");
        scanf("%d", &value);
        if (value == 0) break;
        insertNode(&list1, value);
    }

    // Insert values into the second list
    printf("Enter values for the second sorted list (enter 0 to stop):\n");
    while (1) {
        printf("Enter value: ");
        scanf("%d", &value);
        if (value == 0) break;
        insertNode(&list2, value);
    }

    // Merge the two lists
    mergedList = mergeLists(list1, list2);

    // Display the merged list
    printf("Merged Sorted List: ");
    displayList(mergedList);

    // Free the memory
    freeList(mergedList);

    return 0;
}
