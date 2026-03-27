#include <stdio.h>
#include <ctype.h>
char st[100]; int top=-1;
int p(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}
int main(){
    char a[]="A+B*(C^D-E)^(F+G*H)-I", r[100];
    int i,k=0;
    for(i=0;a[i];i++){
        if(isalnum(a[i])) r[k++]=a[i];
        else if(a[i]=='(') st[++top]=a[i];
        else if(a[i]==')'){
            while(st[top]!='(') r[k++]=st[top--];
            top--;
        }
        else{
            while(top!=-1 && p(st[top])>=p(a[i]))
                r[k++]=st[top--];
            st[++top]=a[i];
        }
    }
while(top!=-1) r[k++]=st[top--];
    r[k]='\0';
printf("%s",r);
}