#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* head1;
struct Node* head2;
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory allocation  failed...");
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void insert(int data)
{
    struct Node* newNode = createNode(data);
    newNode->next=head1;
    head1=newNode;
    printf("Inserted %d in the list...\n", data);
}
void display()
{
    struct Node* ptr = head1;
    if(head1==NULL)
    {
        printf("List is empty...");
        return;
    }
    while(ptr!=NULL)
    {
        printf("%d->", ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
void displayRev()
{
    struct Node* ptr = head2;
    if(head2==NULL)
    {
        printf("List is empty...");
        return;
    }
    while(ptr!=NULL)
    {
        printf("%d->", ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
void reverse()
{
    struct Node* temp = head1;
    struct Node* ptr = NULL;
    struct Node* nextNode = NULL;
    while(temp!=NULL)
    {
        nextNode=temp->next;
        temp->next=ptr;
        ptr=temp;
        temp=nextNode;
    }
    head2 = ptr;
}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    printf("Original List :\n");
    display();
    reverse();
    printf("Reversed List :\n");
    displayRev();
    return 0;
}