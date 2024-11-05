// Write a program to implement a stack with a singly linked list. Given below are abstract definitions of
// functions that you need to implement, where S is a stack, x is an element that can be stored in S, top is the
// end of stack where push and pop operations are allowed, bottom is the other end of the stack. Each node of
// the linked list contains a data item which represents an element of the stack. After initially creating a stack S
// with k elements and with an upper limit on the number of elements as max, taking k, max, and the elements
// of S as input from the user, your program will show a menu-based interface, similar to Question no. 5,
// where the user can choose from the following options: i) Push, ii) Pop, iii) Display, iv) Quit. The menu will
// be displayed repeatedly until the user chooses option (iv). The push and pop functions must call the
// functions isFull and isEmpty, respectively, to check the overflow and underflow conditions, for which
// appropriate messages should be displayed. Note that deleting a node of the linked list means removing the
// node from the linked list and then freeing the storage held by the removed node.
// isEmpty(S) := returns True if S is empty, otherwise returns False.
// isFull(S) := returns True if S is full (i.e. S contains the maximum number of elements), otherwise returns
// False.
// push(S, x) := pushes x to S.
// pop(S) := pops an element x from S and returns x, i.e. returns the popped data item after deleting the
// popped node.
// display(S) := prints all elements of S elegantly from top to bottom (clearly indicating top).


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
