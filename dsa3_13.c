#include <stdio.h>
#include <stdlib.h>
struct mynode
{
    int roll_number;
    char name[50];
    char academic_stream[50];
    struct mynode *next;
    struct mynode *prev;
};
struct mynode *search(struct mynode *head, int roll)
{
    struct mynode *ii = head;
    do
    {
        if (ii->roll_number == roll)
        {
            return ii;
        }
        ii = ii->next;
    } while (ii != head);
    return NULL;
}
void DisplayFromForward(struct mynode *head , int roll)
{
    struct mynode *node=search(head,roll);
    if(node==NULL)
    {
        printf("Roll is not found in list.\n");
        return;
    }
    struct mynode *ii=node;
    printf("\nLIST\n");
    do
    {
        printf("Roll Number: %d\n", ii->roll_number);
        printf("Name: %s", ii->name);
        printf("Academic Stream: %s", ii->academic_stream);
        printf("-------------------------\n");
        ii = ii->next;
    } while (ii != node);
}
void DisplayFromReverse(struct mynode *head , int roll)
{
    struct mynode *node=search(head,roll);
    if(node==NULL)
    {
        printf("Roll is not found in list.\n");
        return;
    }
    struct mynode *ii=node;
    printf("\nLIST\n");
    do
    {
        printf("Roll Number: %d\n", ii->roll_number);
        printf("Name: %s", ii->name);
        printf("Academic Stream: %s", ii->academic_stream);
        printf("-------------------------\n");
        ii = ii->prev;
    } while (ii != node);
}
int main()
{
    struct mynode *head = NULL, *tail = NULL, *newnode = NULL;
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct mynode));
        printf("Enter name: ");
        fgets(newnode->name, 50, stdin);
        printf("Enter roll number: ");
        scanf("%d", &newnode->roll_number);
        getchar();
        printf("Enter academic stream: ");
        fgets(newnode->academic_stream, 50, stdin);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
    }
    int choice;
    int roll;
    struct mynode *temp=NULL;
    while (1)
    {
        printf("\nMENU\n");
        printf("1.Search\n");
        printf("2.DisplayFromForward\n");
        printf("3.DisplayFromReverse\n");
        printf("4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter roll to search: ");
            scanf("%d" ,&roll);
            temp=search(head,roll);
            if(temp!=NULL)
            {
                printf("Found the node in the list.\n");
            }
            else
            {
                printf("Not Found");
            }
            break;
        case 2:
            printf("Enter roll from where to print forward: ");
            scanf("%d" ,&roll);
            DisplayFromForward(head,roll);
            break;
        case 3:
            printf("Enter roll from where to print reverse: ");
            scanf("%d" ,&roll);
            DisplayFromReverse(head,roll);
            break;    
        case 4:
            printf("Quitting the program\n");
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    printList(head);
}