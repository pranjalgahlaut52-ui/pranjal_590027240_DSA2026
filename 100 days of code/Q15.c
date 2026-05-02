#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int arr[m][n];
    int sum = 0;

    // Input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Calculate primary diagonal sum
    for (int i = 0; i < m && i < n; i++) {
        sum += arr[i][i];
    }

    // Output result
    printf("%d", sum);

    return 0;
}