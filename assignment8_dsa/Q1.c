#include <stdio.h>

int main() {
    int n, i, j, temp;
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

    // Bubble Sort
    for(i = 0; i < n - 1; i++) {
        printf("\nPass %d:\n", i + 1);

        for(j = 0; j < n - i - 1; j++) {
            comparisons++;

            if(arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }

        // Display array after each pass
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