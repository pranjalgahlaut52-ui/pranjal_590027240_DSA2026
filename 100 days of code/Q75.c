#include <stdio.h>

#define MAX 1000

int main() {

    int n;
    scanf("%d", &n);

    int arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    // we use offset because prefix sum can be negative
    int offset = 10000;
    int hash[20001];

    for (int i = 0; i < 20001; i++)
        hash[i] = -2;

    hash[offset] = -1;

    for (int i = 0; i < n; i++) {

        prefixSum += arr[i];

        if (hash[prefixSum + offset] != -2) {
            int len = i - hash[prefixSum + offset];
            if (len > maxLen)
                maxLen = len;
        }
        else {
            hash[prefixSum + offset] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}