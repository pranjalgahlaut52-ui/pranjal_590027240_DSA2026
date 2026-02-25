#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int main(){
    struct Node *head=NULL,*temp=NULL,*newNode;
    int n,i,value,key,pos=1,found=0;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d",&value);
        newNode->data=value;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            temp=newNode;
        }else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    printf("Enter element to search: ");
    scanf("%d",&key);
    temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            printf("Element found at position %d",pos);
            found=1;
            break;
        }
        temp=temp->next;
        pos++;
    }
    if(!found)
        printf("Element does not exist");
    return 0;
}