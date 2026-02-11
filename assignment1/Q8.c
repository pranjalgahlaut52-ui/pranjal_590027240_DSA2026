#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data d;

    d.i = 10;
    printf("Integer value: %d\n", d.i);
    d.f = 3.5;
    printf("Float value: %.2f\n", d.f);
    d.c = 'A';
    printf("Character value: %c\n", d.c);
     printf("Size of union: %lu bytes\n", sizeof(d));
    return 0;
}
