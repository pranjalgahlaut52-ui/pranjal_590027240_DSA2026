#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* last=NULL;

// Create list
void create(int n){
    int i,val;
    struct Node* newNode,*temp;
    for(i=0;i<n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d",&val);
        newNode->data=val;
        if(last==NULL){
            last=newNode;
            last->next=last;
        }else{
            newNode->next=last->next;
            last->next=newNode;
            last=newNode;
        }
    }
}

// Insert at beginning
void insertBeg(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if(last==NULL){
        last=newNode;
        last->next=last;
    }else{
        newNode->next=last->next;
        last->next=newNode;
    }
}

// Insert at end
void insertEnd(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if(last==NULL){
        last=newNode;
        last->next=last;
    }else{
        newNode->next=last->next;
        last->next=newNode;
        last=newNode;
    }
}

// Delete from beginning
void deleteBeg(){
    if(last==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp=last->next;
    if(last->next==last){
        last=NULL;
    }else{
        last->next=temp->next;
    }
    free(temp);
}

// Delete from end
void deleteEnd(){
    if(last==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp=last->next;
    if(last->next==last){
        free(last);
        last=NULL;
        return;
    }
    while(temp->next!=last)
        temp=temp->next;
    temp->next=last->next;
    free(last);
    last=temp;
}

// Display and count
void display(){
    if(last==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp=last->next;
    int count=0;
    printf("List: ");
    do{
        printf("%d ",temp->data);
        temp=temp->next;
        count++;
    }while(temp!=last->next);
    printf("\nTotal nodes: %d\n",count);
}

int main(){
    int n,choice,val;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    create(n);
    do{
        printf("\n1.Insert Beginning\n2.Insert End\n3.Delete Beginning\n4.Delete End\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter value: ");
                    scanf("%d",&val);
                    insertBeg(val);
                    break;
            case 2: printf("Enter value: ");
                    scanf("%d",&val);
                    insertEnd(val);
                    break;
            case 3: deleteBeg(); break;
            case 4: deleteEnd(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }while(1);
    return 0;
}