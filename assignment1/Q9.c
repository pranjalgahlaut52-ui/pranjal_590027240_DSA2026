#include <stdio.h>

struct A {
    int i;
    float f;
    char c;
};

union B {
    int i;
    float f;
    char c;
};
int main() {
    printf("Size of structure: %lu bytes\n", sizeof(struct A));
    printf("Size of union: %lu bytes\n", sizeof(union B));
    return 0;
}
