#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed...");
        exit(1);
    }
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data){
    if(root==NULL){
        return createNode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}
void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
void preOrder(struct Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
void deleteTree(struct Node* root){
    if(root!=NULL){
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}
int main(){
    int choice,n;
    struct Node* root=NULL;
    printf("Enter the number of nodes :");
    scanf("%d",&n);
    int data[n];
    printf("Enter the elements :");
    for(int i=0; i<n; i++){
        scanf("%d",&data[i]);
        root=insert(root,data[i]);
    }
    printf("---BINARY TREE OPERATIONS---\n");
    while(1){
        printf("\n1.InOrder Transversal\n 2.PreOrder Transversal\n 3.PostOrder Transversal\n 4.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:inOrder(root);
                   break;
            case 2:preOrder(root);
                   break;
            case 3:postOrder(root);
                   break;
            case 4:deleteTree(root);
                   printf("Memory Freed...\n");
                   printf("Program is exiting...");
                   exit(0);
            default:printf("Invalid choice...");
        }
    }
    return 0;

}
