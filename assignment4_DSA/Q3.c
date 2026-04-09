#include<stdio.h>
#include<stdlib.h>

struct Node{int data;struct Node*next;};
struct Node *front=NULL,*rear=NULL;

void enqueue(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Queue Overflow\n");return;}
    newNode->data=value;
    newNode->next=NULL;
    if(rear==NULL){front=rear=newNode;}
    else{rear->next=newNode;rear=newNode;}
}

void dequeue(){
    if(front==NULL){printf("Queue Underflow\n");return;}
    struct Node*temp=front;
    printf("%d removed\n",front->data);
    front=front->next;
    if(front==NULL)rear=NULL;
    free(temp);
}

void display(){
    if(front==NULL){
        printf("Queue empty\n");return;}
    struct Node*temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);temp=temp->next;}
    printf("\n");
}

void peek(){
    if(front==NULL)printf("Queue empty\n");
    else printf("Front: %d\n",front->data);
}

int main(){
    enqueue(10);enqueue(20);enqueue(30);
    display();peek();
    dequeue();display();
    return 0;
}