#include <stdio.h>

void sequentialSearch(int arr[], int size, int item);
void binarySearch(int arr[], int n, int item);
void bubbleSort(int arr[], int n);

int main() {
    int size, choice;

    // Input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int arr[size];

    // Input array elements
    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Ask user for search method
    printf("Choose search method:\n1. Sequential Search\n2. Binary Search\nEnter your choice: ");
    scanf("%d", &choice);
    
    // Input item to search
    int item;
    printf("Enter the element to search: ");
    scanf("%d", &item);
    
    switch (choice) {
        case 1:
            sequentialSearch(arr, size, item);
            break;
        case 2:
            // Sort the array before binary search
            bubbleSort(arr, size);
            binarySearch(arr, size, item);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

// Sequential search function
void sequentialSearch(int arr[], int size, int item) {
    int r = -1, count = 0;

    for (int j = 0; j < size; j++) {
        if (arr[j] == item) {
            if (r == -1) r = j; // First occurrence
            count++;
        }
    }

    if (r != -1) {
        printf("Element first found at index %d and its occurrence: %d\n", r, count);
    } else {
        printf("Element not found.\n");
    }
}

// Binary search function
void binarySearch(int arr[], int n, int item) {
    int beg = 0, end = n - 1, mid;

    while (beg <= end) {
        mid = (beg + end) / 2;
        if (arr[mid] == item) {
            printf("Item found at position %d\n", mid + 1);
            return; // Item found, exit the function
        } else if (item < arr[mid]) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    printf("Item not found.\n");
}

// Bubble sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

