#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
    int coeff,exp;
    struct Node* next;
};

struct Node* head=NULL;

void insert(int c,int e){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->coeff=c;
    newNode->exp=e;
    newNode->next=NULL;
    if(head==NULL)
        head=newNode;
    else{
        struct Node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
}

void display(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%dx^%d",temp->coeff,temp->exp);
        if(temp->next!=NULL)
            printf(" + ");
        temp=temp->next;
    }
    printf("\n");
}

double evaluate(int x){
    struct Node* temp=head;
    double result=0;
    while(temp!=NULL){
        result+=temp->coeff*pow(x,temp->exp);
        temp=temp->next;
    }
    return result;
}

int main(){
    int n,c,e,x,i;
    printf("Enter number of terms: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter coefficient and exponent: ");
        scanf("%d%d",&c,&e);
        insert(c,e);
    }
    printf("Polynomial: ");
    display();
    printf("Enter value of x: ");
    scanf("%d",&x);
    printf("Result: %.2lf",evaluate(x));
    return 0;
}