#include<stdio.h>
#include<stdlib.h>
struct Node{int data;struct Node *prev,*next;};
struct Node *head=NULL,*tail=NULL;

void create(int n){
    int i,val;struct Node *newNode;
    for(i=0;i<n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter value: ");scanf("%d",&val);
        newNode->data=val;
        if(head==NULL){
            head=tail=newNode;
            head->next=head->prev=head;
        }else{
            newNode->prev=tail;
            newNode->next=head;
            tail->next=newNode;
            head->prev=newNode;
            tail=newNode;
        }
    }
}

void display(){
    if(head==NULL){printf("List empty\n");return;}
    struct Node *temp=head;int count=0;
    printf("List: ");
    do{
        printf("%d ",temp->data);
        temp=temp->next;
        count++;
    }while(temp!=head);
    printf("\nTotal nodes: %d\n",count);
}

void insertBeg(int val){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if(head==NULL){
        head=tail=newNode;
        head->next=head->prev=head;
    }else{
        newNode->next=head;
        newNode->prev=tail;
        head->prev=newNode;
        tail->next=newNode;
        head=newNode;
    }
}

void insertEnd(int val){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if(head==NULL){
        head=tail=newNode;
        head->next=head->prev=head;
    }else{
        newNode->prev=tail;
        newNode->next=head;
        tail->next=newNode;
        head->prev=newNode;
        tail=newNode;
    }
}

void deleteBeg(){
    if(head==NULL){printf("List empty\n");return;}
    if(head==tail){
        free(head);
        head=tail=NULL;
    }else{
        struct Node *temp=head;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
}

void deleteEnd(){
    if(head==NULL){printf("List empty\n");return;}
    if(head==tail){
        free(tail);
        head=tail=NULL;
    }else{
        struct Node *temp=tail;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);
    }
}

int main(){
    int n,choice,val;
    printf("Enter number of nodes: ");scanf("%d",&n);
    create(n);
    do{
        printf("\n1.InsertBeg\n2.InsertEnd\n3.DeleteBeg\n4.DeleteEnd\n5.Display\n6.Exit\n");
        printf("Choice: ");scanf("%d",&choice);
        switch(choice){
            case 1: printf("Value: ");scanf("%d",&val);insertBeg(val);break;
            case 2: printf("Value: ");scanf("%d",&val);insertEnd(val);break;
            case 3: deleteBeg();break;
            case 4: deleteEnd();break;
            case 5: display();break;
            case 6: exit(0);
            default: printf("Invalid\n");
        }
    }while(1);
    return 0;
}