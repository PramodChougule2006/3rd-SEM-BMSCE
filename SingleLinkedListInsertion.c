#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
}*newNode;
struct Node* start = NULL;
struct Node* createNode(int data) {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void display() {
    struct Node* ptr = start;
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
void insertBeginning(int data) {
    newNode = createNode(data);
    newNode->next = start; 
    start = newNode;        
    printf("Inserted %d at the beginning.\n", data);
}
void insertEnd(int data) {
    newNode = createNode(data);
    if (start == NULL) {
        start = newNode;
        printf("Inserted %d at the end (list was empty).\n", data);
        return;
    }
    struct Node* ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    printf("Inserted %d at the end.\n", data);
}
void insertPosition(int data, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        insertBeginning(data);
        return;
    }
    newNode = createNode(data);
    struct Node* ptr = start;
    int count = 1;
    while (ptr != NULL && count < pos - 1) {
        ptr = ptr->next;
        count++;
    }
    if (ptr == NULL) {
        printf("Position is out of bounds.\n");
        free(newNode);
        return;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    printf("Inserted %d at position %d.\n", data, pos);
}
int main() {
    int data,pos,choice;
    while(1) {
        printf("\n1.Insert At Beginning.\n 2.Insert At End.\n 3.Insert At Any Position.\n 4.Display\n 5.Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter the element :");
                    scanf("%d", &data);
                    insertBeginning(data);
                    break;
            case 2: printf("Enter the element :");
                    scanf("%d", &data);
                    insertEnd(data);
                    break;
            case 3: printf("Enter the element :");
                    scanf("%d", &data);
                    printf("Enter the position :");
                    scanf("%d", &pos);
                    insertPosition(data, pos);
                    break;
            case 4: display();
                    break;
            case 5: printf("\nProgram is exiting...\n");
                    exit(0);
            default: printf("Invalid choice...");
        }
    }
    return 0;
}
