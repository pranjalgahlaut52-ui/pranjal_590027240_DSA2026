#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr;

    printf("Enter the number: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));  
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array elements:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);   
    return 0;
}
