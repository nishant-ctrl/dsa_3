// Write a program to create a singly linked list (a chain) and then display the odd numbers and the even
// numbers of the list in two separate lines. Create a linked list L containing n nodes, where each node contains
// one data item called key which stores an integer, by taking n and the values of key for each node of L as
// input from the user. Print all the key values of L in the correct order, starting from the first node, called the
// head, and ending at the last node, called the tail, in the 1st line of the final output of your program. Print all
// the odd key values of L in the 2nd line of the final output of your program, and print all the even key values
// of L in the 3rd line of the final output of your program. Display the output in the format given below
#include <stdio.h>
#include <stdlib.h>
struct mynode
{
    int key;
    struct mynode *next;
};

struct mynode *addToList(struct mynode *head)
{
    struct mynode *newnode=NULL,*ii=NULL;
    newnode=malloc(sizeof(struct mynode));
    newnode->next=NULL;
    printf("Enter Key Value: ");
    scanf("%d" ,&newnode->key);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        for (ii = head; ii->next!=NULL; ii=ii->next);
        ii->next=newnode;
    }
    return head;
}
void printList(struct mynode *head)
{
    struct mynode *ii;
    printf("L: ");
    for (ii = head; ii!=NULL; ii=ii->next)
    {
        printf("%d -> ",ii->key);
    }
    printf("NULL");
    printf("\n");
}
void printOdds(struct mynode *head)
{
    struct mynode *ii;
    printf("Odd Values: ");
    for (ii = head; ii!=NULL; ii=ii->next)
    {
        if(ii->key%2!=0)
        {
            printf("%d ",ii->key);
        }
    }
    printf("\n");
}
void printEvens(struct mynode *head)
{
    struct mynode *ii;
    printf("Even Values: ");
    for (ii = head; ii!=NULL; ii=ii->next)
    {
        if(ii->key%2==0)
        {
            printf("%d ",ii->key);
        }
    }
    printf("\n");
}

int main()
{
    struct mynode *head=NULL;
    int n;
    printf("How many elements you  want to enter in list: ");
    scanf("%d" ,&n);
    for(int i=0;i<n;i++)
    {
        head=addToList(head);
    }
    printList(head);
    printOdds(head);
    printEvens(head);
    return 0;
}