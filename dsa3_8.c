#include <stdio.h>
#include <stdlib.h>
struct mynode
{
    int key;
    struct mynode *next;
    struct mynode *prev;
};
int count_list(struct mynode *head)
{
    struct mynode *ii;
    int num = 0;
    for (ii = head; ii != NULL; ii = ii->next)
    {
        num++;
    }
    return num;
}
struct mynode *create_node(int k)
{
    struct mynode *newnode = NULL;
    newnode = malloc(sizeof(struct mynode));
    newnode->key = k;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
int IsFull(struct mynode *head, int max)
{
    if (count_list(head) == max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsEmpty(struct mynode *head)
{
    if (count_list(head)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void add(struct mynode **head,struct mynode **tail, struct mynode *n, int max)
{
    struct mynode *ii;
    if (IsFull(*head, max) == 1)
    {
        printf("Queue Overflow.\n");
        return;
    }
    if (*head == NULL)
    {
        *head = n;
        *tail = n;
    }
    else
    {
        (*tail)->next=n;
        n->prev=(*tail);
        (*tail)=n;
    }
}
void delete(struct mynode **head , struct mynode **tail)
{
    if (IsEmpty(*head) == 1)
    {
        printf("Queue Underflow.\n");
        return;
    }
    struct mynode *ii, *temp;
    int item;
    temp=(*head);
    item=temp->key;
    (*head)=(*head)->next;
    if(*head!=NULL)
    {
        (*head)->prev=NULL;
    }
    temp->next=NULL;
    free(temp);
    printf("Deleted item is %d.", item);
}
void Display(struct mynode *head)
{
    struct mynode *ii;
    printf("L: ");
    printf("NULL ");
    for (ii = head; ii != NULL; ii = ii->next)
    {
        printf("%d ", ii->key);
    }
    printf("NULL");
    printf("\n");
}
int main()
{
    int max, k;
    printf("Enter the maximum size of Queue: ");
    scanf("%d", &max);
    printf("How many nodes you want to enter initially? ");
    scanf("%d", &k);
    if (k <= 0 || k > max)
    {
        printf("Not Possible.");
        return 0;
    }
    int value, item;
    struct mynode *head = NULL, *tail=NULL,*n = NULL;
    for (int i = 0; i < k; i++)
    {
        printf("Enter key value of node: ");
        scanf("%d", &value);
        n = create_node(value);
        add(&head, &tail, n, max);
    }
    int choice;
    while (1)
    {
        printf("--MENU--\n");
        printf("1.Add\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &value);
            n = create_node(value);
            add(&head, &tail, n, max);
            break;
        case 2:
            delete(&head,&tail);
            break;
        case 3:
            Display(head);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
