#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* start=NULL;
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed...");
    }
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void insert(int data){
    struct Node* newNode = createNode(data);
    newNode->next=start;
    if(start!=NULL)
        start->prev=newNode;
    newNode->prev=NULL;
    start=newNode;
    printf("Inserted %d into the list...", data);
}
void deleteBasedOnValue(int value){
    if(start==NULL){
        printf("List is empty...");
        return;
    }
    struct Node* ptr=start;
    while(ptr!=NULL && ptr->data!=value){
        ptr=ptr->next;
    }
    if(ptr==NULL){
        printf("%d not found in the list...", value);
        return;
    }
    if(ptr==start){
        start=ptr->next;
        if(start!=NULL)
            start->prev=NULL;
    }
    else if(ptr->next==NULL){
        ptr->prev->next=NULL;
    }
    else{
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
    }
    free(ptr);
    printf("Deleted %d from the list...", value);
}
void display(){
    if(start==NULL){
        printf("List is empty...");
        return;
    }
    struct Node* ptr=start;
    while(ptr!=NULL){
        printf("%d<->", ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
int main(){
    int choice,value;
    printf("\nDouble Linked List Operations :\n");
    while(1){
        printf("\n1.Insert Beginning\n 2.Delete\n 3.Display\n 4.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the value to be inserted :");
                   scanf("%d",&value);
                   insert(value);
                   break;
            case 2:printf("Enter the element to delete :");
                   scanf("%d",&value);
                   deleteBasedOnValue(value);
                   break;
            case 3:display();
                   break;
            case 4:printf("Program is exiting...");
                   exit(0);
            default:printf("Invalid choice...");
        }
    }
    return 0;
}



