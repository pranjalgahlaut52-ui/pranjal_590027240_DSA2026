#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {
    struct Student *s = NULL;
    int n = 0, choice, i, delIndex;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1: // Add record
            s = realloc(s, (n + 1) * sizeof(struct Student));
            if (s == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }

            printf("Enter ID: ");
            scanf("%d", &s[n].id);
            printf("Enter Name: ");
            scanf("%s", s[n].name);
            printf("Enter Marks: ");
            scanf("%f", &s[n].marks);

            n++;
            break;

        case 2: // Display records
            if (n == 0) {
                printf("No records available.\n");
            } else {
                printf("\nStudent Records:\n");
                for (i = 0; i < n; i++) {
                    printf("ID: %d, Name: %s, Marks: %.2f\n",
                           s[i].id, s[i].name, s[i].marks);
                }
            }
            break;

        case 3: // Delete record
            if (n == 0) {
                printf("No records to delete.\n");
                break;
            }

            printf("Enter index to delete (1 to %d): ", n);
            scanf("%d", &delIndex);

            if (delIndex < 1 || delIndex > n) {
                printf("Invalid index.\n");
                break;
            }

            // Shift records
            for (i = delIndex - 1; i < n - 1; i++) {
                s[i] = s[i + 1];
            }

            n--;
            s = realloc(s, n * sizeof(struct Student));
            printf("Record deleted.\n");
            break;

        case 4: // Exit
            free(s);
            printf("Memory freed. Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
