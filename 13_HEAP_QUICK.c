#include <stdio.h>

// Function prototypes
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);
void printArray(int arr[], int n);

int main() {
    int n;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr1[n], arr2[n];

    // Input array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i]; // Copy for quick sort
    }

    // Heap Sort
    printf("\nOriginal Array for Heap Sort: ");
    printArray(arr1, n);

    heapSort(arr1, n);
    printf("Sorted Array using Heap Sort: ");
    printArray(arr1, n);

    // Quick Sort
    printf("\nOriginal Array for Quick Sort: ");
    printArray(arr2, n);

    quickSort(arr2, 0, n - 1);
    printf("Sorted Array using Quick Sort: ");
    printArray(arr2, n);

    return 0;
}

// Heap Sort implementation
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // Move current root to end
        heapify(arr, i, 0);     // Call max heapify on the reduced heap
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

// Quick Sort implementation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1);  // Sort left part
        quickSort(arr, pi + 1, high); // Sort right part
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = low - 1;       // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;           // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Utility function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
