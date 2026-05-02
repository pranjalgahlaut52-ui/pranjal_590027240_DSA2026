#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100000

int stack[MAX];
int top = -1;

// Push
void push(int val) {
    stack[++top] = val;
}

// Pop
int pop() {
    return stack[top--];
}

// Evaluate expression
int calculate(char* s) {
    int num = 0;
    char op = '+';

    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        // Build number
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        }

        // If operator or end
        if ((!isdigit(ch) && ch != ' ') || i == n - 1) {

            if (op == '+') {
                push(num);
            }
            else if (op == '-') {
                push(-num);
            }
            else if (op == '*') {
                int topVal = pop();
                push(topVal * num);
            }
            else if (op == '/') {
                int topVal = pop();
                push(topVal / num); // truncates toward zero
            }

            op = ch;
            num = 0;
        }
    }

    // Sum stack
    int result = 0;
    while (top != -1) {
        result += pop();
    }

    return result;
}

int main() {
    char s[100000];

    // Input expression (with spaces)
    fgets(s, sizeof(s), stdin);

    int result = calculate(s);

    printf("%d", result);

    return 0;
}