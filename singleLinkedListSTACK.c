#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* top = NULL;
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
void push(int data)
{
    struct Node* newNode=createNode(data);
    newNode->next=top;
    top=newNode;
    printf("Inserted %d into the List...", data);
}
void pop()
{
    if(top==NULL)
    {
        printf("List is empty...");
        return;
    }
    struct Node* temp = NULL;
    temp=top;
    top=top->next;
    printf("Deleted %d from the List...", temp->data);
    free(temp);
}
void display()
{
    struct Node* ptr = NULL;
    if(top==NULL)
    {
        printf("List is empty...");
        return;
    }
    ptr=top;
    while(ptr!=NULL)
    {
        printf("%d->", ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice,data;
    printf("\nStack operations using single linked list :\n");
    while(1)
    {
        printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:printf("Enter the element :");
                   scanf("%d", &data);
                   push(data);
                   break;
            case 2:pop();
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
