#include <stdio.h>

int main() {
    int n, i, j, key;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Shift elements greater than key
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Display array after each insertion
        printf("\nAfter inserting element %d (Pass %d):\n", key, i);
        for(int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    // Final sorted array
    printf("\nSorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}