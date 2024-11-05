#include <stdio.h>
#include <stdlib.h>
struct mynode
{
    int key;
    struct mynode *next;
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
struct mynode *push(struct mynode *head, struct mynode *n, int max)
{
    struct mynode *ii;
    if (IsFull(head, max) == 1)
    {
        printf("Stack Overflow.\n");
        return head;
    }
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        for (ii = head; ii->next != NULL; ii = ii->next)
            ;
        ii->next = n;
    }
    return head;
}
struct mynode *pop(struct mynode *head)
{
    if (IsEmpty(head) == 1)
    {
        printf("Stack Underflow.\n");
        return head;
    }
    struct mynode *ii, *temp = head;
    int item;
    if (count_list(head)==1)
    {
        item = head->key;
        temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        for (ii = head; ii->next != NULL; ii = ii->next)
        {
            temp = ii;
        }
        item = ii->key;
        temp->next = NULL;
        free(ii);
    }
    printf("Deleted item is %d.", item);
    return head;
}
void Display(struct mynode *head)
{
    struct mynode *ii;
    printf("L: ");
    for (ii = head; ii != NULL; ii = ii->next)
    {
        printf("%d -> ", ii->key);
    }
    printf("NULL");
    printf("\n");
}
int main()
{
    int max, k;
    printf("Enter the maximum size of Stack: ");
    scanf("%d", &max);
    printf("How many nodes you want to enter initially? ");
    scanf("%d", &k);
    if (k <= 0 || k > max)
    {
        printf("Not Possible.");
        return 0;
    }
    int value, item;
    struct mynode *head = NULL, *n = NULL;
    for (int i = 0; i < k; i++)
    {
        printf("Enter key value of node: ");
        scanf("%d", &value);
        n = create_node(value);
        head = push(head, n, max);
    }
    int choice;
    while (1)
    {
        printf("--MENU--\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Dispaly\n");
        printf("4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &value);
            n = create_node(value);
            head = push(head, n, max);
            break;
        case 2:
            head=pop(head);
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
