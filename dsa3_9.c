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
struct mynode *Delete_middle_node(struct mynode *head)
{
    struct mynode *ii,*temp;
    int n=count_list(head);
    int count=0;
    if(n<2)
    {
        printf("There is no middle node.\n");
        return head;
    }
    if(n==2)
    {
        temp=head;
        ii=head->next;
        ii->prev=NULL;
        temp->next=NULL;
        head=ii;
        free(temp);
        return head;
    }
    for(ii=head ; ii->next!=NULL ; ii=ii->next)
    {
        count++;
        if(n%2!=0 && count==n/2)
        {
            temp=ii->next;
            ii->next=temp->next;
            temp->next->prev=ii;
            temp->next=NULL;
            temp->prev=NULL;
            free(temp);
            break;
        }
        if(n%2==0 && count==n/2-1)
        {
            temp=ii->next;
            ii->next=temp->next;
            temp->next->prev=ii;
            temp->next=NULL;
            temp->prev=NULL;
            free(temp);
            break;
        }
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
    head=Delete_middle_node(head);
    Display(head);
    return 0;
}