#include <stdio.h>
#include <stdlib.h>
// MACRO FOR MALLOC
#define MALLOC(p, size, type) \
    p = (type*)malloc(size * sizeof(type)); \
    if (p == NULL) { \
        printf("\nInsufficient memory\n"); \
        exit(1); \
    }

// DEFINING NODE TYPE
typedef struct node {
    int info;
    struct node *link; 
} NODE;

int count=-1;

NODE* Insertfront(NODE *first, int item) // for INSERTION AKA PUSH
{
    NODE *temp;  // Corrected to pointer type
    MALLOC(temp, 1, NODE);  // Correct memory allocation NOT struct node
    temp->info = item;
    temp->link = first;// stacking
    return temp;// back to first
}

NODE* Deletefront(NODE *first) {
    NODE *temp;
    if (first == NULL) {  // No need to dereference, first is already a pointer
        printf("\nTHE STACK IS EMPTY\n");
        return first;
    }
    temp = first;
    temp= temp->link;  // Move first to the next node of stack
    printf("\nDeleted element is = %d\n",first->info);
    free(first);
    first=NULL;  
    return temp;// Back as front
}

void display(NODE *first)
{
    NODE *temp;
    temp = first;
    if(temp==NULL)
    {
        printf("\nSTACK IS EMPTY\n");
        exit(0);
    }
    while(temp!=NULL)
    {
        printf("%d,\t",temp->info);
        temp=temp->link;
    }
    printf("\nEND OF LIST");
}

int main() 
{
    NODE *first = NULL;  // Correct initialization to pointer
    int c,size;
    printf("THIS PROGRAM IS TO IMPLEMENT STACKS USING SLL\n");
    printf("STACK OPERATIONS ARE INSERTION AND DELETION\n");
    printf("enter size of stack \n");
    scanf("%d",&size);
    while(1)
    {
      
        printf("\nEnter\n1=push onto a stack\n2=pop an element\n3=dispaly the stack and exit\n");
        scanf("%d", &c);
        switch (c) {
          case 1: {
            count++;
             int item;
             if(count<size)
             {
                
                printf("\nEnter the element to be pushed onto the stack\n");
                scanf("%d", &item);
                first = Insertfront(first, item);
                break;
             }
             else
             {
                 printf("\n stack overflow\n pop out an element\n");
                 break;
             }
          }
          case 2:
           {
            count--;

            if(count>=0)
            {
              first = Deletefront(first);
              break;
            }
            else{
                printf("stack underflow \npush an element\n");
                break;
            }
           }
           case 3:
           {
            printf("\nPRINTING THE STACK {in the order = topmost element to the bottommost element} \n");
            display(first);
            exit(0);
           }
          default:
            printf("\nWRONG CHOICE\n");
            exit(0);
    }
    }
    return 0;
}