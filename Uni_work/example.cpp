// Insertion in Linear Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insert_at_beg();
void insert_at_end();
void insert_at_loc();
void disp();

node *start = NULL;

int main()
{
    int ch;

    while (1)
    {
        printf("\n\n---- Options Are ----");
        printf("\n1 - Insertion at beginning");
        printf("\n2 - Insertion at end");
        printf("\n3 - Insertion at location");
        printf("\n4 - Display");
        printf("\n5 - Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_at_beg();
            break;

        case 2:
            insert_at_end();
            break;

        case 3:
            insert_at_loc();
            break;

        case 4:
            disp();
            break;

        case 5:
            exit(0);

        default:
            printf("\nWrong Choice!");
        }
    }

    return 0;
}

// Insert at beginning
void insert_at_beg()
{
    node *ptr;

    ptr = (node *)malloc(sizeof(node));

    printf("\nEnter the value: ");
    scanf("%d", &ptr->data);

    ptr->next = NULL;

    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        ptr->next = start;
        start = ptr;
    }

    printf("\nNode inserted successfully!");
}

// Insert at end
void insert_at_end()
{
    node *ptr;

    ptr = (node *)malloc(sizeof(node));

    printf("\nEnter the value: ");
    scanf("%d", &ptr->data);

    ptr->next = NULL;

    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        node *temp;
        temp = start;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = ptr;
    }

    printf("\nNode inserted successfully!");
}

// Insert at a particular location
void insert_at_loc()
{
    int loc;
    node *ptr;

    ptr = (node *)malloc(sizeof(node));

    printf("\nEnter the value: ");
    scanf("%d", &ptr->data);

    ptr->next = NULL;

    printf("\nEnter the location: ");
    scanf("%d", &loc);

    // If list is empty
    if (start == NULL)
    {
        if (loc == 1)
        {
            start = ptr;
        }
        else
        {
            printf("\nInvalid location!");
            free(ptr);
            return;
        }
    }
    // Insert at beginning
    else if (loc == 1)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        node *temp;
        temp = start;

        // Move temp to the node before required location
        for (int i = 1; i < loc - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("\nInvalid location!");
            free(ptr);
            return;
        }

        ptr->next = temp->next;
        temp->next = ptr;
    }

    printf("\nNode inserted successfully!");
}

// Display the linked list
void disp()
{
    node *temp;

    temp = start;

    if (temp == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("\nYou have entered the following data:\n");

        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL");
    }
}