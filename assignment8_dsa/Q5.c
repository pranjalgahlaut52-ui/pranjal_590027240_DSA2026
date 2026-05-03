#include <stdio.h>

// Partition function (Lomuto scheme)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // choose last element as pivot
    int i = low - 1;        // index of smaller element

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // place pivot in correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort function (recursive)
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort left and right parts
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, i;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call Quick Sort
    quickSort(arr, 0, n - 1);

    // Output sorted array
    printf("\nSorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}