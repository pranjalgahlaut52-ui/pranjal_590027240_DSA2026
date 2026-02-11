#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, sum = 0;
    float avg;
    int *arr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int)); 
    printf("Enter elements:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    } avg = (float)sum / n;

    printf("Array elements: ");
    for(i = 0; i < n; i++)
        
    printf("%d ", arr[i]);
    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f", avg);

    free(arr);   
    return 0;
}
