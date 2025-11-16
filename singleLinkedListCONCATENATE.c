#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head1 = NULL;
struct Node* head2 = NULL;
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory allocation failed...");
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void insertFirstList(int data)
{
    struct Node* newNode = createNode(data);
    newNode->next=head1;
    head1=newNode;
    printf("Inserted %d in the list1...\n", data);
}
void insertSecondList(int data)
{
    struct Node* newNode = createNode(data);
    newNode->next=head2;
    head2=newNode;
    printf("Inserted %d in the list2...\n", data);
}
void concatenate()
{
    if(head1==NULL)
    {
        head1=head2;
        return;
    }
    if(head2==NULL)
        return;
    struct Node* ptr = head1;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=head2;
}
void display()
{
    if(head1==NULL)
    {
        printf("List is empty...");
    }
    struct Node* ptr = head1;
    while(ptr!=NULL)
    {
        printf("%d->", ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
int main()
{
    insertFirstList(1);
    insertFirstList(2);
    insertFirstList(3);
    insertSecondList(4);
    insertSecondList(5);
    concatenate();
    display();
    return 0;
}