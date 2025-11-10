#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
}*newNode;
struct Node* start = NULL;
struct Node* createNode(int data)
{
    newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Overflow...");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};
void display()
{
    struct Node* ptr = start;
    if(ptr == NULL)
    {
        printf("Empty...");
        return;
    }
    printf("List Elements :");
    while(ptr!=NULL)
    {
        printf("%d->" , ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
void insert(int data)
{
    newNode = createNode(data);
    newNode->next = start;
    start = newNode;
    printf("Inserted %d\n" , data);
}
void deleteAtBeginning()
{
    if(start == NULL)
    {
        printf("Empty...");
        return;
    }
    struct Node* ptr = start;
    start = start->next;
    printf("Deleted %d from Beginning" , ptr->data);
    free(ptr);
}
void deleteAtEnd()
{
    if(start == NULL)
    {
        printf("Empty...");
        return;
    }
    if(start->next == NULL)
    {
        printf("Deleted %d from end" , start->data);
        free(start);
        start = NULL;
        return;
    }
    struct Node* ptr = start;
    struct Node* prev = NULL;
    while(ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    printf("Deleted %d from end" , ptr->data);
    free(ptr);
}
void deleteAtPosition(int pos)
{
    if(start == NULL)
    {
        printf("Empty...");
        return;
    }
    if(pos == -1)
    {
        deleteAtBeginning();
        return;
    }
    struct Node* ptr = start;
    struct Node* prev = NULL;
    int i=1;
    while(ptr != NULL && i<pos)
    {
        prev = ptr;
        ptr = ptr->next;
        i++;
    }
    if(ptr == NULL)
    {
        printf("Out Of Bound...");
        return;
    }
    prev->next = ptr->next;
    printf("Deleted %d from position %d " , ptr->data , pos);
    free(ptr);
}
int main()
{
    int choice,pos;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    while(1)
    {
        printf("\n 1.Delete Beginning\n 2.Delete End\n 3.Delete Position\n 4.Display\n 5.Exit\n");
        printf("Enter your choice :");
        scanf("%d" , &choice);
        switch(choice)
        {
            case 1:deleteAtBeginning();
                   break;
            case 2:deleteAtEnd();
                   break;
            case 3:printf("Enter the position you want to delete :");
                   scanf("%d" , &pos);
                   deleteAtPosition(pos);
                   break;
            case 4:display();
                   break;
            case 5:printf("Program is exiting...");
                   exit(0);
            default:printf("Invalid choice...");
        }
    }
    return 0;
}

