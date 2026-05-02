#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define Node (stack node)
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {

        // Skip spaces
        if (exp[i] == ' ')
            continue;

        // If digit, push to stack
        if (isdigit(exp[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--; // adjust index
            push(&stack, num);
        }
        else {
            // Operator: pop two operands
            int val2 = pop(&stack);
            int val1 = pop(&stack);

            int result;

            switch (exp[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default:
                    printf("Invalid Operator\n");
                    return 0;
            }

            push(&stack, result);
        }
    }

    // Final result
    return pop(&stack);
}

int main() {
    char exp[100];

    // Input postfix expression (with spaces)
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("%d", result);

    return 0;
}