#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int top = -1;
int stack[MAX_SIZE];
void push(int data)
{
    if(top == MAX_SIZE-1)
    {
        printf("Stack Overflow: Cannot add element to the stack\n");
    }
    else
    {
        top++;
        stack[top] = data;
        printf("Pushed %d into the stack...\n", data);
    }
}
void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow: Cannot remove element from the stack...\n");
        exit(0);
    }
    else
    {
        int popped_value = stack[top];
        top--;
        printf("Popped %d from the stack...\n", popped_value);
    }
}
void display()
{
    if(top == -1)
    {
        printf("The stack is empty...\n");
        exit(0);
    }
    else
    {
        printf("Stack elements are:\n");
        for(int i=top ; i>=0 ; i--)
        {
            printf("%d\n",stack[i]);
        }
        exit(0);
    }
}
int main()
{
    int choice,value;
    while(1)
    {
        printf("Stack Operations :\n");
        printf("\n1.Push.\n 2.Pop.\n 3.Display. 4.Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter the value to push :");
                    scanf("%d", &value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: printf("\nProgram is exiting...\n");
                    return -1;
            default: printf("Invalid choice...");
        }
    }
    return 0;
}
