#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Point to itself
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If the list is empty, make the new node the head
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = newNode; // Link the last node to the new node
    }
    newNode->next = *head; // Link the new node to the head
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to %d)\n", head->data); // Indicate the circular link
}

// Main function to demonstrate the circular linked list
int main() {
    struct Node* head = NULL;

    // Inserting elements
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    // Display the circular linked list
    printf("Circular Linked List: ");
    display(head);

    return 0;
}

