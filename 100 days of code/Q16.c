#include <stdio.h>

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Frequency count
    for(int i = 0; i < n; i++) {
        int count = 1;

        // Skip already counted elements
        if(arr[i] == -1)
            continue;

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = -1;  // mark as counted
            }
        }

        printf("%d:%d\n", arr[i], count);
    }

    return 0;
}