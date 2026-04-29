#include <stdio.h>

int hashFunction(int sapID) {
    int lastThree = sapID % 1000;
    return lastThree % 10;   // family 0–9
}

int main() {
    int sapID;

    printf("Enter SAP ID: ");
    scanf("%d", &sapID);

    int family = hashFunction(sapID);

    printf("Student belongs to family: %d\n", family);

    return 0;
}
