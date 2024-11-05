// Write a program to implement the operations, given below, on a given singly linked list L, where each node
// of L contains one data item called key. Each operation should be implemented with a function according to
// the abstract definition of the operation given below, where L is a singly linked list, n is a node that can be a
// member of L, and the key contained in any node ni is denoted as ni.key. After initially creating L with m
// nodes by taking m and the key values of L as input from the user, the user will be shown a menu-based
// interface where the user will choose to execute an operation. The menu will be repeatedly displayed until
// the user chooses to quit. The first node of L is called the head, and the last node of L is called the tail.
// (i) search(L, k) := Searches for the value k in L; returns n if n is the first occurrence of a node in L
// such that n.key = k; returns NIL if there is no such node in L.
// (ii) count(L) := Returns the number of nodes in L.
// (iii) addAtHead(L, n) := Adds a node n to the beginning of L, making n the new head of L.
// (iv) addAtTail(L, n) := Adds a node n to the end of L, making n the new tail of L.
// (v) insert(L, n, p) := Inserts a node n in L at position p.
// Page 1 of 5
// (vi) deleteByPosition(L, p) := Removes node n from position p of L, and frees the storage held by n.
// (vii) deleteByValue(L, k) := Removes every node ni from L where ni.key = k, and frees the storage held
// by the removed nodes.
// (viii) maximum(L) := Returns a pointer to the node with the largest key value in L (returns the first such
// node if multple nodes store the largest key value in L).
// (ix) minimum(L) := Returns a pointer to the node with the smallest key value in L (similar to
// maximum).
// (x) empty(L) := Removes all nodes of L, and frees the storage held by the removed nodes.
// (xi) print(L) := Prints the key values of L elegantly in the correct order, from head to tail.
// Also, define the following function (abstract definition given) to create a node, and call this function from
// other functions whenever a new node needs to be created.
//  create_node(k) := creates and returns a new node n with n.key = k; returns NIL if new node could
// not be created.


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