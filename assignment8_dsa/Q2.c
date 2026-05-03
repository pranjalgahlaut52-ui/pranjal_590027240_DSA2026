#include <stdio.h>

int main() {
    int n, i, j, minIndex, temp;
    int comparisons = 0, swaps = 0;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Selection Sort
    for(i = 0; i < n - 1; i++) {
        minIndex = i;

        for(j = i + 1; j < n; j++) {
            comparisons++;
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap if needed
        if(minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }

        // Display array after each pass
        printf("\nPass %d:\n", i + 1);
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

    // Display counts
    printf("\n\nTotal comparisons = %d", comparisons);
    printf("\nTotal swaps = %d\n", swaps);

    return 0;
}