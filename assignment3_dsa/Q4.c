#include <stdio.h>
int main() {
    char s[100], stack[100];
    int top = -1, i, ok = 1;
 printf("Enter expression: ");
    scanf("%s", s);
    for(i = 0; s[i]; i++) {
     if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            stack[++top] = s[i];
        else if(s[i]==')' || s[i]=='}' || s[i]==']') {
         if(top==-1) { ok=0; break; }
            char ch = stack[top--];
            if((s[i]==')' && ch!='(') ||
               (s[i]=='}' && ch!='{') ||
               (s[i]==']' && ch!='[')) {
                ok=0; break;
            }
        }
    }
    if(top!=-1) ok=0;
    printf(ok ? "Balanced" : "Not Balanced");
    return 0;
}