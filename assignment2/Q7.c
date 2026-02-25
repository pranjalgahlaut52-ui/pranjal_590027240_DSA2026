#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev,*next;
};

struct Node *head=NULL,*tail=NULL;

// Create list
void create(int n){
    int i,val;
    struct Node *newNode;
    for(i=0;i<n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d",&val);
        newNode->data=val;
        newNode->prev=newNode->next=NULL;
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
}

// Display forward & count
void display(){
    struct Node *temp=head;
    int count=0;
    printf("Forward: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\nTotal nodes: %d\n",count);
}

// Backward traversal
void displayReverse(){
    struct Node *temp=tail;
    printf("Backward: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

// Insert at beginning
void insertBeg(int val){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->prev=NULL;
    newNode->next=head;
    if(head!=NULL)
        head->prev=newNode;
    else
        tail=newNode;
    head=newNode;
}

// Insert at end
void insertEnd(int val){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=tail;
    if(tail!=NULL)
        tail->next=newNode;
    else
        head=newNode;
    tail=newNode;
}

// Insert after given value
void insertAfter(int key,int val){
    struct Node *temp=head;
    while(temp!=NULL && temp->data!=key)
        temp=temp->next;
    if(temp==NULL){
        printf("Value not found\n");
        return;
    }
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=NULL)
        temp->next->prev=newNode;
    else
        tail=newNode;
    temp->next=newNode;
}

// Delete from beginning
void deleteBeg(){
    if(head==NULL){ printf("List empty\n"); return; }
    struct Node *temp=head;
    head=head->next;
    if(head!=NULL)
        head->prev=NULL;
    else
        tail=NULL;
    free(temp);
}

// Delete from end
void deleteEnd(){
    if(tail==NULL){ printf("List empty\n"); return; }
    struct Node *temp=tail;
    tail=tail->prev;
    if(tail!=NULL)
        tail->next=NULL;
    else
        head=NULL;
    free(temp);
}

// Delete given node by value
void deleteValue(int key){
    struct Node *temp=head;
    while(temp!=NULL && temp->data!=key)
        temp=temp->next;
    if(temp==NULL){ printf("Value not found\n"); return; }
    if(temp==head){ deleteBeg(); return; }
    if(temp==tail){ deleteEnd(); return; }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}

int main(){
    int n,choice,val,key;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    create(n);
    do{
        printf("\n1.Insert Beg\n2.Insert End\n3.Insert After\n4.Delete Beg\n5.Delete End\n6.Delete Value\n7.Display\n8.Reverse\n9.Exit\n");
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Value: "); scanf("%d",&val); insertBeg(val); break;
            case 2: printf("Value: "); scanf("%d",&val); insertEnd(val); break;
            case 3: printf("After value: "); scanf("%d",&key);
                    printf("New value: "); scanf("%d",&val);
                    insertAfter(key,val); break;
            case 4: deleteBeg(); break;
            case 5: deleteEnd(); break;
            case 6: printf("Delete value: "); scanf("%d",&key);
                    deleteValue(key); break;
            case 7: display(); break;
            case 8: displayReverse(); break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }while(1);
    return 0;
}