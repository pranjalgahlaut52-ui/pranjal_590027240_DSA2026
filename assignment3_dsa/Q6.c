#include <stdio.h>
#include <ctype.h>

int main() {
    int st[100], top=-1, i;
    char a[]="23*54*+9-";

    for(i=0;a[i];i++){
        if(isdigit(a[i]))
            st[++top]=a[i]-'0';
        else{
            int b=st[top--], c=st[top--];
            if(a[i]=='+') st[++top]=c+b;
            if(a[i]=='-') st[++top]=c-b;
            if(a[i]=='*') st[++top]=c*b;
            if(a[i]=='/') st[++top]=c/b;
        }
    }

    printf("%d",st[top]);
}