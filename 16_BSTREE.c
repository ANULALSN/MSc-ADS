#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function prototypes
Node* createNode(int data);
Node* insert(Node* root, int data);
Node* search(Node* root, int data);
void inOrderTraversal(Node* root);
void freeTree(Node* root);

int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. In-order Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted.\n", value);
                break;

            case 2: // Search
                printf("Enter value to search: ");
                scanf("%d", &value);
                Node* foundNode = search(root, value);
                if (foundNode) {
                    printf("Found: %d\n", foundNode->data);
                } else {
                    printf("%d not found in the BST.\n", value);
                }
                break;

            case 3: // In-order Traversal
                printf("In-order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 4: // Exit
                freeTree(root);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new value into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a value in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function for in-order traversal of the BST
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to free the allocated memory for the tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

