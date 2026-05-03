#include <stdio.h>

int main() {
    int n, i, key;
    int found = 0;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Linear Search
    printf("\nElement found at positions: ");
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("%d ", i);  // printing index
            found = 1;
        }
    }

    // If not found
    if(found == 0) {
        printf("\nElement not found in the array.\n");
    }

    printf("\n");

    return 0;
}