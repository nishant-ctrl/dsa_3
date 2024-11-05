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