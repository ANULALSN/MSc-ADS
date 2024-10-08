#include <stdio.h>
#include <stdlib.h>

#define MAX 6

// Function prototypes
void linearQueue();
void circularQueue();
void enqueue(int element);
int dequeue();
void display();
int isFull();
int isEmpty();

// Global variables for linear queue
int front = -1, rear = -1, maxSizeLinear;
int linearQueueArray[100];

// Global variables for circular queue
int circularQueueArray[MAX];
int frontCircular = -1, rearCircular = -1;

// Main function
int main() {
    int choice;
    printf("Choose Queue Type:\n1. Linear Queue\n2. Circular Queue\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the size of the linear queue: ");
            scanf("%d", &maxSizeLinear);
            linearQueue();
            break;
        case 2:
            circularQueue();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

// Linear Queue Functions
void linearQueue() {
    int choice;
    while (1) {
        printf("\nLinear Queue Operations:\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rear == maxSizeLinear - 1) {
                    printf("Overflow: Queue is full.\n");
                } else {
                    int item;
                    printf("Enter the element to insert: ");
                    scanf("%d", &item);
                    if (front == -1) front = 0;
                    rear++;
                    linearQueueArray[rear] = item;
                    printf("Element inserted: %d\n", item);
                }
                break;
            case 2:
                if (front == -1 || front > rear) {
                    printf("Underflow: Queue is empty.\n");
                } else {
                    int item = linearQueueArray[front];
                    printf("Element deleted: %d\n", item);
                    front++;
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

// Circular Queue Functions
void circularQueue() {
    int choice;
    while (1) {
        printf("\nCircular Queue Operations:\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Overflow: Queue is full.\n");
                } else {
                    int element;
                    printf("Enter the element to insert: ");
                    scanf("%d", &element);
                    enqueue(element);
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

// Linear Queue Display
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", linearQueueArray[i]);
    }
    printf("\n");
}

// Circular Queue Functions
void enqueue(int element) {
    if (frontCircular == -1 && rearCircular == -1) {
        frontCircular = 0;
        rearCircular = 0;
    } else {
        rearCircular = (rearCircular + 1) % MAX;
    }
    circularQueueArray[rearCircular] = element;
    printf("Element inserted: %d\n", element);
}

int dequeue() {
    if (isEmpty()) {
        printf("Underflow: Queue is empty.\n");
        return -1; // Indicate underflow
    }
    int element = circularQueueArray[frontCircular];
    printf("Element deleted: %d\n", element);
    if (frontCircular == rearCircular) {
        frontCircular = rearCircular = -1; // Reset for empty queue
    } else {
        frontCircular = (frontCircular + 1) % MAX;
    }
    return element;
}

int isFull() {
    return (rearCircular + 1) % MAX == frontCircular;
}

int isEmpty() {
    return frontCircular == -1 && rearCircular == -1;
}

// Display for Circular Queue
void displayCircular() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the circular queue: ");
    int i = frontCircular;
    do {
        printf("%d ", circularQueueArray[i]);
        i = (i + 1) % MAX;
    } while (i != (rearCircular + 1) % MAX);
    printf("\n");
}

