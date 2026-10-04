#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at beginning */
void insertFront(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

/* Insert at end */
void insertEnd(int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

/* Insert after a given value */
void insertAfter(int target, int value)
{
    struct Node *temp = head;
    struct Node *newNode;

    while (temp != NULL)
    {

        if (temp->data == target)
        {

            newNode = (struct Node *)malloc(sizeof(struct Node));

            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;

            return;
        }

        temp = temp->next;
    }

    printf("Value not found\n");
}

/* Delete from beginning */
void deleteFront()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);
}

/* Delete from end */
void deleteEnd()
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    /* Only one node */
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

/* Delete a given value */
void deleteValue(int value)
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    /* Delete first node */
    if (head->data == value)
    {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    prev = head;
    temp = head->next;

    while (temp != NULL)
    {

        if (temp->data == value)
        {
            prev->next = temp->next;
            free(temp);
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Value not found\n");
}

/* Traversal */
void display()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{

    insertFront(20);
    insertFront(10);

    insertEnd(30);
    insertEnd(40);

    printf("List: ");
    display();

    insertAfter(20, 25);

    printf("After insertion: ");
    display();

    deleteFront();

    printf("After deleting front: ");
    display();

    deleteEnd();

    printf("After deleting end: ");
    display();

    deleteValue(25);

    printf("After deleting 25: ");
    display();

    return 0;
}