#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Function prototypes
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtPosition(int data, int position);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int position);
void search(int key);
void display();

// Head pointer for the linked list
struct node *head = NULL;

int main() {
    int choice, data, position, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Specific Position\n");
        printf("7. Search a Node\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node at a specific position
void insertAtPosition(int data, int position) {
    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }
    
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        struct node *temp = head;
        for (int i = 0; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds!\n");
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to delete a node at the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted node from the beginning.\n");
}

// Function to delete a node at the end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted the only node in the list.\n");
        return;
    }
    
    struct node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Deleted node from the end.\n");
}

// Function to delete a node at a specific position
void deleteAtPosition(int position) {
    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }

    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct node *temp = head;

    if (position == 0) {
        head = temp->next; // Changed head
        free(temp); // Free old head
        printf("Deleted node at position %d.\n", position);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    struct node *next = temp->next->next;
    free(temp->next); // Free memory
    temp->next = next; // Unlink the deleted node
    printf("Deleted node at position %d.\n", position);
}

// Function to search for a node
void search(int key) {
    struct node *temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Node with value %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Node with value %d not found in the list.\n", key);
}

// Function to display the linked list
void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("The linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

