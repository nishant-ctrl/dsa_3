// Write a program to implement search and display operations, as defined below, on a doubly linked circular
// linked list. Take as input from the user a doubly linked circular list L of k nodes where every node contains
// the following attributes: i) roll_number which should be unique for each node, ii) name of student, and iii)
// academic_stream of student. Let the oldest node of L be denoted head, and the newest node of L be denoted
// tail, and every new node nw be added to L at the position after tail, i.e. the next pointer of tail will be made
// to point to nw, before tail is updated. After creating L, print elegantly the attributes of all nodes of L from
// head to tail, and then implement the following functions (abstract definitions given) with a menu-based
// interface, where n is a node in a doubly linked circular list L, r is a value of type the same as the type of
// roll_number, “forward direction” means the direction in which the next pointer of each node of L points,
// Page 3 of 5
// and “backward direction” means the direction in which the previous pointer of each node of L points. The
// menu is displays repeatedly in a loop until the user chooses to quit.
// i) search(r, L) := Returns the node n in L where n.roll_number = r if such a node exists in L, otherwise
// returns NIL.
// ii) displayFrom(r, L) := Prints the attributes of all nodes of L starting from the node n where
// n.roll_number = r and ending at the node m where m is the previous node of n, traversing the circular
// list L in the forward direction. Displays nothing if search(r, L) is NIL.
// iii) displayFrom_InReverse(r, L) := Prints the attributes of all nodes of L starting from the node n
// where n.roll_number = r and ending at the node q where q is the next node of n, traversing the
// circular list L in the backward direction. Prints nothing if search(r, L) is NIL.
// A representation of the results of the three aforementioned functions is given below.
// If L is represented by the following arrangement of nodes, where n1 is the next node of n5 and n5 is the
// previous node of n1,
// … ↔ n1 ↔ n2 ↔ n3 ↔ n4 ↔ n5 ↔ …
// and n3.roll_number = r, then
// search(r, L) returns n3
// and
// displayFrom(r, L) prints
//  n3, n4, n5, n1, n2
// and
// displayFrom_InReverse(r, L) prints
// n3, n2, n1, n5, n4



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