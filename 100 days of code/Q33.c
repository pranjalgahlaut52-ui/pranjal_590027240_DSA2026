#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = value;
}

// Pop operation
bool pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return false;
    }
    top--;
    return true;
}

// Display stack from top to bottom
void display() {
    if (top == -1) {
        cout << "Stack is empty";
        return;
    }

    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
}

int main() {
    int n, m, value;

    cin >> n;

    // Push elements
    for (int i = 0; i < n; i++) {
        cin >> value;
        push(value);
    }

    cin >> m;

    // Perform pop operations safely
    for (int i = 0; i < m; i++) {
        if (!pop()) break;  // stop if underflow occurs
    }

    display();

    return 0;
}