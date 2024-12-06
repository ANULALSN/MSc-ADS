#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;  // Array to store the heap elements
    int size;    // Current number of elements in the heap
    int capacity; // Maximum number of elements the heap can hold
} MaxHeap;

// Function prototypes
MaxHeap* createHeap(int capacity);
void insert(MaxHeap *heap, int key);
int deleteMax(MaxHeap *heap);
int peek(MaxHeap *heap);
void heapifyUp(MaxHeap *heap, int index);
void heapifyDown(MaxHeap *heap, int index);
void freeHeap(MaxHeap *heap);

int main() {
    int capacity;
    printf("Enter the capacity of the heap: ");
    scanf("%d", &capacity);

    MaxHeap *heap = createHeap(capacity); // Create a heap with user-defined capacity
    int choice, key;

    while (1) {
        printf("\nOptions:\n");
        printf("1. Insert\n");
        printf("2. Delete Max\n");
        printf("3. Peek Max\n");
        printf("4. Print Heap\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &key);
                insert(heap, key);
                break;
            case 2:
                key = deleteMax(heap);
                if (key != -1) {
                    printf("Deleted Max: %d\n", key);
                }
                break;
            case 3:
                key = peek(heap);
                if (key != -1) {
                    printf("Max Element: %d\n", key);
                } else {
                    printf("Heap is empty!\n");
                }
                break;
            case 4:
                printf("Heap Elements: ");
                for (int i = 0; i < heap->size; i++) {
                    printf("%d ", heap->array[i]);
                }
                printf("\n");
                break;
            case 5:
                freeHeap(heap);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Create a max-heap
MaxHeap* createHeap(int capacity) {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int *)malloc(capacity * sizeof(int));
    return heap;
}

// Insert a new key into the heap
void insert(MaxHeap *heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Heap is full!\n");
        return;
    }
    heap->array[heap->size] = key; // Add the new key
    heap->size++;                   // Increase the size
    heapifyUp(heap, heap->size - 1); // Restore heap property
}

// Delete the maximum element from the heap
int deleteMax(MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty!\n");
        return -1; // Indicates empty heap
    }
    int root = heap->array[0]; // Store the root value
    heap->array[0] = heap->array[--heap->size]; // Replace root with the last element
    heapifyDown(heap, 0); // Restore heap property
    return root;
}

// Peek at the maximum element
int peek(MaxHeap *heap) {
    return (heap->size > 0) ? heap->array[0] : -1; // Return root or -1 if empty
}

// Restore the heap property by moving up
void heapifyUp(MaxHeap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->array[index] > heap->array[parent]) {
            // Swap if the current node is greater than its parent
            int temp = heap->array[index];
            heap->array[index] = heap->array[parent];
            heap->array[parent] = temp;
            index = parent; // Move up to the parent index
        } else {
            break; // If the heap property is satisfied, exit
        }
    }
}

// Restore the heap property by moving down
void heapifyDown(MaxHeap *heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->array[right] > heap->array[largest]) {
        largest = right;
    }
    
    if (largest != index) {
        // Swap and continue down
        int temp = heap->array[index];
        heap->array[index] = heap->array[largest];
        heap->array[largest] = temp;
        heapifyDown(heap, largest);
    }
}

// Free the heap memory
void freeHeap(MaxHeap *heap) {
    free(heap->array);
    free(heap);
}
