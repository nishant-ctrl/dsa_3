// Write a program to delete every alternate node of a doubly linked list L, starting with the 2nd node. After
// taking L as input from the user, modify L so that the nodes at even positions, i.e. 2nd node, 4th node, 6th node,
// and so on, of L are deleted. Assume that every node of L contains one data item. Note that deleting a node of
// a linked list means removing the node from the linked list and then freeing the storage held by that node.
// Display L both before and after the modification as the final output of your program.
// Sample Final Output
// Original list: 40, 30, 10, 20, 50, 25, 70
// Modified list: 40, 10, 50, 70


#include <stdio.h>
#include <stdlib.h>
struct mynode 
{
    int key;
    struct mynode *next;
    struct mynode *prev;
};
void Display(struct mynode *head)
{
    struct mynode *ii;
    printf("L: ");
    printf("NULL ");
    for (ii = head; ii != NULL; ii = ii->next)
    {
        printf(" %d ", ii->key);
    }
    printf(" NULL");
    printf("\n");
}
int count_list(struct mynode *head)
{
    struct mynode *ii;
    int num=0;
    for(ii=head ; ii!=NULL ; ii=ii->next)
    {
        num++;
    }
    return num;
}
struct mynode *Delete_alternate_node(struct mynode *head)
{
    struct mynode *ii,*temp;
    int count=0;
    if(count_list(head)<=1)
    {
        printf("Only one Node.\n");
        return head;
    }
    for(ii=head ; ii!=NULL ; ii=ii->next)
    {
        temp=ii->next;
        if(temp->next!=NULL)
        {
            ii->next=temp->next;
            ii->next->prev=ii;
        }
        if(temp->next==NULL)
        {
            ii->next=NULL;
        }
        temp->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
    return head;
}
int main()
{
    struct mynode *head=NULL , *tail=NULL , *newnode=NULL;
    int n,val;
    printf("How many nodes you want to enter: ");
    scanf("%d" ,&n);
    if(n<1)
    {
        printf("Invalid number of Nodes.\n");
        return 0;
    }
    for(int i=0 ; i<n ; i++)
    {
        newnode=malloc(sizeof(struct mynode));
        printf("Enter key: ");
        scanf("%d" ,&newnode->key);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    Display(head);
    head=Delete_alternate_node(head);
    Display(head);
    return 0;
}