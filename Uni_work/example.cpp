#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

struct node *create_node()
{
    struct node *head = NULL;
    return head;
}

void insertBeg(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter element : ");
    scanf("%d", ptr->data);
    if (head == NULL)
    {
        head = ptr;
        printf("%d inserted\n", ptr->data);
    }
    else
    {
        ptr->next = head;
        head = ptr;
        printf("%d inserted\n", ptr->data);
    }
}
void insertEnd(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter element : ");
    scanf("%d", ptr->data);
    if (head == NULL)
    {
        head = ptr;
        printf("%d inserted(empty)\n", ptr->data);
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
    }
}

void dis(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Free(struct node *head1)
{
    while (head1 != NULL)
    {
        struct node *temp = head1;
        head1 = head1->next;
        free(temp);
    }
    free(head1);
}

int main()
{
    struct node *head1 = create_node();
    insertBeg(head1);
    insertEnd(head1);
    insertEnd(head1);
    insertEnd(head1);
    dis(head1);
    Free(head1);

    return 0;
}