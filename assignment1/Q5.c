#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int n, i;
    struct Student *s;

    printf("Enter number of students: ");
    scanf("%d", &n);

    s = malloc(n * sizeof(struct Student));   
    for(i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    } printf("\nStudent Details:\n");
    for(i = 0; i < n; i++) {
        printf("Roll: %d, Name: %s, Marks: %.2f\n",
               s[i].roll, s[i].name, s[i].marks);
    }

    free(s);   
    return 0;
}
