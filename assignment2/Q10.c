#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int roll;
    char name[50];
    float marks;
    struct Node* next;
};

struct Node* head=NULL;

void insert(){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter Roll No: ");scanf("%d",&newNode->roll);
    printf("Enter Name: ");scanf(" %[^\n]",newNode->name);
    printf("Enter Marks: ");scanf("%f",&newNode->marks);
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
    if(head==NULL){printf("No records\n");return;}
    struct Node* temp=head;
    while(temp!=NULL){
        printf("Roll:%d Name:%s Marks:%.2f\n",temp->roll,temp->name,temp->marks);
        temp=temp->next;
    }
}

void search(int r){
    struct Node* temp=head;
    while(temp!=NULL){
        if(temp->roll==r){
            printf("Record Found -> Roll:%d Name:%s Marks:%.2f\n",temp->roll,temp->name,temp->marks);
            return;
        }
        temp=temp->next;
    }
    printf("Record not found\n");
}

void delete(int r){
    if(head==NULL){printf("List empty\n");return;}
    struct Node *temp=head,*prev=NULL;
    while(temp!=NULL && temp->roll!=r){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){printf("Record not found\n");return;}
    if(prev==NULL)
        head=temp->next;
    else
        prev->next=temp->next;
    free(temp);
    printf("Record deleted\n");
}

int main(){
    int choice,r;
    do{
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        printf("Choice: ");scanf("%d",&choice);
        switch(choice){
            case 1: insert();break;
            case 2: printf("Enter Roll to delete: ");scanf("%d",&r);delete(r);break;
            case 3: printf("Enter Roll to search: ");scanf("%d",&r);search(r);break;
            case 4: display();break;
            case 5: exit(0);
            default: printf("Invalid\n");
        }
    }while(1);
    return 0;
}