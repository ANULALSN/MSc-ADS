  #include <stdio.h>

int main() {
    int n, i, j, x, temp, pos = -1, low = 0, high, mid;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n]; // Declare array after getting value of n

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &x);

    // Bubble sort the array (not efficient but works for demonstration)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    low = 0;
    high = n - 1;

    // Binary search
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == x) {
            pos = mid;
            break;
        } else if (a[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (pos == -1) {
        printf("Element found in the array\n");
    } else {
        printf("Element found at position %d\n", pos);
    }

    return 0;
}

