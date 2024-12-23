#include <stdio.h>
#include <stdlib.h>

// Define the structure of the queue
struct Queue {
    int *arr;
    int front, rear, size;
    int capacity;
};

// Function to create a queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = 0;
    queue->size = 0;
    queue->arr = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return queue->size == queue->capacity;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->arr[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

// Function to get the size of the queue
int getSize(struct Queue* queue) {
    return queue->size;
}

// Function to find the maximum element in the queue
int findMax(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    int max = dequeue(queue); // Start with the first element as the max
    enqueue(queue, max); // Re-enqueue it to preserve the queue

    int size = getSize(queue);
    
    // Traverse the queue and find the max element
    for (int i = 1; i < size; i++) {
        int current = dequeue(queue);
        if (current > max) {
            max = current;
        }
        enqueue(queue, current); // Re-enqueue to preserve the queue
    }

    return max;
}

// Function to display the queue (for testing purposes)
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    int size = getSize(queue);
    int i = queue->front;
    for (int j = 0; j < size; j++) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(10); // Create a queue with capacity 10

    // Enqueue some values
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 15);
    enqueue(queue, 30);
    enqueue(queue, 25);

    printf("Queue elements: ");
    displayQueue(queue);

    // Find the maximum element in the queue
    int max = findMax(queue);
    printf("The maximum element in the queue is: %d\n", max);

    // Display the queue again to confirm it remains intact
    printf("Queue after finding the max element: ");
    displayQueue(queue);

    return 0;
}
