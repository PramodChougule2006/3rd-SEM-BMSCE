#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory allocation failed...");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void enqueue(int data)
{
    struct Node* newNode = createNode(data);
    if(front==NULL && rear==NULL)
    {
        front=rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
    printf("Inserted %d in the List...", data);
}
void dequeue()
{
    if(front==NULL)
    {
        printf("List is empty...");
        return;
    }
    struct Node* temp = front;
    front=front->next;
    if(front==NULL)
        rear=NULL;
    printf("Deleted %d from the list...", temp->data);
    free(temp);
}
void display()
{
    struct Node* ptr = NULL;
    if(front==NULL && rear==NULL)
    {
        printf("List is empty...");
        return;
    }
    ptr=front;
    while(ptr!=NULL)
    {
        printf("%d<-", ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice,data;
    printf("\nQueue operations using single linked list :\n");
    while(1)
    {
        printf("\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:printf("Enter the element :");
                   scanf("%d", &data);
                   enqueue(data);
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:printf("\nProgram is exiting...\n");
                   exit(0);
            default:printf("Invalid choice...");
        }
    }
    return 0;
}