#include <stdio.h>
#include <string.h>

#define MAX 100
char queue[MAX];
int front = 0, rear = -1;
void enqueue(char ch) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    queue[++rear] = ch;
}char dequeue() {
    if (front > rear) {
        return '\0';
    }
    return queue[front++];
}int main() {
    char str[MAX];
    int i, len, flag = 1;
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);
    for (i = 0; i < len; i++) {
        enqueue(str[i]);
    }
    for (i = 0; i < len; i++) {
        char ch = dequeue();
        if (str[i] != ch) {
            flag = 0;
            break;
        }
    }if (flag)
        printf("String is Palindrome\n");
    else
        printf("String is Not Palindrome\n");
        return 0;
}