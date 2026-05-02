#include <stdio.h>
#include <stdlib.h>

// Simple hash map using arrays (for demo, works for moderate constraints)
#define SIZE 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Hash map for prefix sums
    int hash[SIZE] = {0};

    int prefixSum = 0;
    int count = 0;

    // Important: prefix sum 0 occurs once initially
    hash[0 + SIZE/2] = 1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Shift index to handle negative values
        int index = prefixSum + SIZE/2;

        if (hash[index] > 0) {
            count += hash[index];
        }

        hash[index]++;
    }

    printf("%d\n", count);

    return 0;
}