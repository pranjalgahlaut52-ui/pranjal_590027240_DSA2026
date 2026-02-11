#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, i, maxIndex = 0;

    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct Employee *emp = (struct Employee *)malloc(n * sizeof(struct Employee));

    if (emp == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    } for (i = 1; i < n; i++) {
        if (emp[i].salary > emp[maxIndex].salary) {
            maxIndex = i;
        }
    }
    printf("\nEmployee with highest salary:\n");
    printf("ID: %d\n", emp[maxIndex].id);
    printf("Name: %s\n", emp[maxIndex].name);
    printf("Salary: %.2f\n", emp[maxIndex].salary);

    // Free allocated memory
    free(emp);

    return 0;
}
