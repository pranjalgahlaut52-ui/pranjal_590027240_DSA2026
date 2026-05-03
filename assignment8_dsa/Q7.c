#include <stdio.h>

// Recursive Binary Search function
int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;  // element found

        else if (key < arr[mid])
            return binarySearch(arr, low, mid - 1, key);

        else
            return binarySearch(arr, mid + 1, high, key);
    }

    return -1; // element not found
}

int main() {
    int n, i, key, result;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    printf("Enter %d elements (in sorted order):\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Call recursive binary search
    result = binarySearch(arr, 0, n - 1, key);

    // Output result
    if(result != -1)
        printf("\nElement found at index: %d\n", result);
    else
        printf("\nElement not found in the array.\n");

    return 0;
}
