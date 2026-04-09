#include <stdio.h>
#define MAX 5

int q1[MAX], q2[MAX];
int front1=-1,rear1=-1,front2=-1,rear2=-1;

void enqueue(int q[],int *front,int *rear,int val){
    if(*rear==MAX-1)return;
    if(*front==-1)*front=0;
    q[++(*rear)]=val;
}

int dequeue(int q[],int *front,int *rear){
    if(*front==-1)return -1;
    int val=q[*front];
    if(*front==*rear)*front=*rear=-1;
    else (*front)++;
    return val;
}

int isEmptyQueue(int front){return front==-1;}

/* (i) Push */
void push(int val){
    enqueue(q2,&front2,&rear2,val);

    while(!isEmptyQueue(front1)){
        enqueue(q2,&front2,&rear2,dequeue(q1,&front1,&rear1));
    }

    int *tf=&front1,*tr=&rear1;
    front1=front2;rear1=rear2;
    front2=-1;rear2=-1;
}

/* (ii) Pop */
void pop(){
    if(isEmptyQueue(front1)){printf("Stack Empty\n");return;}
    printf("%d popped\n",dequeue(q1,&front1,&rear1));
}

/* (iii) Peek */
void peek(){
    if(isEmptyQueue(front1))printf("Stack Empty\n");
    else printf("Top: %d\n",q1[front1]);
}

/* (iv) isEmpty */
void isEmpty(){
    if(isEmptyQueue(front1))printf("Stack is Empty\n");
    else printf("Stack is NOT Empty\n");
}
void display(){
    if(isEmptyQueue(front1)){printf("Empty\n");return;}
    for(int i=front1;i<=rear1;i++)printf("%d ",q1[i]);
    printf("\n");
}

int main(){
    push(10);push(20);push(30);
    display();
    peek();
    pop();
    display();
    isEmpty();
    return 0;
}