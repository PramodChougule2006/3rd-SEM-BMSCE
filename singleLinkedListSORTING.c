#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* start = NULL;
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory allocation failed..");
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void insert(int data)
{
    struct Node* newNode = createNode(data);
    newNode->next=start;
    start = newNode;
    printf("Inserted %d in the list...\n", data);
}
void sorting(){
    struct Node* ptr1=start;
    struct Node* ptr2;
    while(ptr1!=NULL){
        ptr2=ptr1->next;
        while(ptr2!=NULL){
            if(ptr1->data > ptr2->data){
                int temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
}
void display(){
    if(start==NULL){
        printf("List is empty...");
        return;
    }
    struct Node* ptr = start;
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
int main(){
    insert(6);
    insert(4);
    insert(7);
    insert(1);
    sorting();
    display();
    return 0;
}