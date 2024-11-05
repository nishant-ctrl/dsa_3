#include <stdio.h>
#include <stdlib.h>
struct mynode
{
    int key;
    struct mynode *next;
};

struct mynode *addAtTail(struct mynode *head, struct mynode *n)
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

void print(struct mynode *head)
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
struct mynode *create_node(int k)
{
    struct mynode *newnode = NULL;
    newnode = malloc(sizeof(struct mynode));
    newnode->key = k;
    newnode->next = NULL;
    return newnode;
}
struct mynode *search(struct mynode *head , int k)
{
    struct mynode *ii;
    if(head==NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }
    for (ii = head; ii != NULL; ii = ii->next)
    {
        if (ii->key == k)
        {
            return ii;
        }
    }
    return NULL;    
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
struct mynode *addAtHead(struct mynode *head , struct mynode *n)
{
    if(head==NULL)
    {
        head=n;
    }
    else
    {
        n->next=head;
        head=n;
    }
    return head;
}
int max(struct mynode *head)
{
    struct mynode *ii;
    if(head==NULL)
    {
        printf("List is empty.\n");
        return 99999;
    }
    int max_val=head->key;
    for(ii=head ; ii!=NULL ; ii=ii->next)
    {
        if(ii->key>=max_val)
        {
            max_val=ii->key;
        }
    }
    return max_val;
}
int min(struct mynode *head)
{
    struct mynode *ii;
    if(head==NULL)
    {
        printf("List is empty.\n");
        return -99999;
    }
    int min_val=head->key;
    for(ii=head ; ii!=NULL ; ii=ii->next)
    {
        if(ii->key<=min_val)
        {
            min_val=ii->key;
        }
    }
    return min_val;
}
struct mynode *empty(struct mynode *head)
{
    struct mynode *ii=NULL,*temp=NULL;
    if(head!=NULL)
    {
        while(head!=NULL)
        {
            temp=head;
            head=head->next;
            free(temp);
        }
    }
    return head;
}
struct mynode *insertAtPosition(struct mynode *head , struct mynode *n , int position)
{
    struct mynode *ii;
    int count=count_list(head);
    if(position<0 || position>count+1)
    {
        printf("Invalid Position.\n");
        return head;
    }
    if(position==0 || position==1)
    {
        head=addAtHead(head,n);
        return head;
    }
    if(position==count+1)
    {
        head=addAtTail(head,n);
        return head;
    }
    int i=0;
    for(struct mynode * ii=head ; ii->next!=NULL ; ii=ii->next)
    {
        i++;
        if(i==position-1)
        {
            n->next=ii->next;
            ii->next=n;
        }
    }
    return head;
}
struct mynode *deleteByPosition(struct mynode *head , int position)
{
    struct mynode *temp=NULL,*ii=NULL;
    if(position<0 || position>count_list(head))
    {
        printf("Invalid Position.\n");
        return head;
    }
    if(position==0 || position==1)
    {
        temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    if(position==count_list(head))
    {
        for(ii=head ; ii->next!=NULL ; ii=ii->next)
        {
            temp=ii;
        }
        temp->next=NULL;
        free(ii);
        return head;
    }
    int i=0;
    for(ii=head ; ii->next!=NULL ; ii=ii->next)
    {
        i++;
        if(i==position-1)
        {
            temp=ii->next;
            ii->next=ii->next->next;
            free(temp);
            break;
        }
    }
    return head;
}
struct mynode *deleteByValue(struct mynode *head , int value)
{
    struct mynode *ii=NULL,*temp=NULL;
    for(ii=head ; ii->next!=NULL ; )
    {
        if(ii->next->key==value)
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
    if(head->key==value)
    {
        temp=head;
        head=head->next;
        free(head);
    }
    return head;
}
int main()
{
    int m;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &m);
    int k;
    struct mynode *head = NULL;
    for (int i = 0; i < m; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &k);
        struct mynode *newnode = create_node(k);
        head = addAtTail(head, newnode);
    }
    int choice,position,val;
    int count=0;
    struct mynode *temp;
    struct mynode *n;
    while (1)
    {
        printf("\nMENU\n");
        printf("1.Search\n");
        printf("2.Count\n");
        printf("3.addAtHead\n");
        printf("4.addAtTail\n");
        printf("5.Insert at position\n");
        printf("6.Delete at position\n");
        printf("7.Delete by Value\n");
        printf("8.Maximun\n");
        printf("9.Minimun\n");
        printf("10.Empty\n");
        printf("11.Print\n");
        printf("12.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to search: ");
            scanf("%d", &k);
            temp=search(head, k);
            if(temp==NULL)
            {
                printf("Element not found.\n");
            }
            else
            {
                printf("Element found and the key value is %d\n. ",temp->key);
            }
            temp=NULL;
            break;
        case 2:
            count=count_list(head);
            printf("Number of elements in the linked list: %d\n", count);
            break;
        case 3:
            printf("Enter the element to add at head: ");
            scanf("%d", &k);
            n = create_node(k);
            head = addAtHead(head, n);
            break;
        case 4:
            printf("Enter the element to add at tail: ");
            scanf("%d", &k);
            n = create_node(k);
            head = addAtTail(head, n);
            break;
        case 5:
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            printf("Enter the element to insert: ");
            scanf("%d", &k);
            n=create_node(k);
            head = insertAtPosition(head, n, position);
            break;
        case 6:
            printf("Enter the position to delete: ");
            scanf("%d", &k);
            head = deleteByPosition(head, k);
            break;
        case 7:
            printf("Enter the value to delete: ");
            scanf("%d", &val);
            head = deleteByValue(head, val);
            break;
        case 8:
            printf("Maximum element is: %d\n", max(head));
            break;
        case 9:
            printf("Minimum element is: %d\n", min(head));
            break;
        case 10:
            head=empty(head);
            break;
        case 11:
            print(head);
            break;
        case 12:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}