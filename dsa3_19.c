#include <stdio.h>
#include <stdlib.h>

struct mynode
{
    char *key;
    struct mynode *next;
};
struct mynode *createNode(char word[])
{
    struct mynode *n=malloc(sizeof(struct mynode));
    n->key=word;
    n->next=NULL;
    return n;
}
int my_strcmp(char str1[] , char str2[]) {
    int i;
    for (i = 0; str1[i] && str1[i] == str2[i]; i++);
    return str1[i] - str2[i];
}


struct mynode *addToList(struct mynode *head , struct mynode *n)
{
    struct mynode *ii;
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        for (ii = head; ii->next != NULL; ii = ii->next);
        ii->next = n;
    }
    return head;
}
struct mynode *delete(struct mynode *head , char *word)
{
    struct mynode *ii=NULL,*temp=NULL;
    for(ii=head ; ii->next!=NULL ; )
    {
        if(my_strcmp(ii->next->key,word)==0)
        {
            temp=ii->next;
            ii->next=ii->next->next;
            free(temp);
        }
        else
        {
            ii=ii->next;
        }
    }
    if(my_strcmp(head->key,word)==0)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    return head;
}
void print(struct mynode *head)
{
    struct mynode *ii;
    printf("L: ");
    for (ii = head; ii != NULL; ii = ii->next)
    {
        printf("%s -> ", ii->key);
    }
    printf("NULL");
    printf("\n");
}
int main(int argc , char *argv[])
{
    struct mynode *head=NULL,*n=NULL;
    char *temp;
    for(int i=1 ; i<argc ; i++)
    {
        temp=argv[i];
        n=createNode(temp);
        head=addToList(head,n);
    }
    print(head);
    char charValue[50];
    printf("Enter word to delete: ");
    scanf("%s" ,charValue);
    head=delete(head,charValue);
    print(head);
    return 0;
}