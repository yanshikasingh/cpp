#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at front */
void insertFront(int value)
{

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

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
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
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
            newNode->prev = temp;

            if (temp->next != NULL)
            {
                temp->next->prev = newNode;
            }

            temp->next = newNode;

            return;
        }

        temp = temp->next;
    }

    printf("Value not found\n");
}

/* Delete from front */
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

    if (head != NULL)
    {
        head->prev = NULL;
    }

    free(temp);
}

/* Delete from end */
void deleteEnd()
{

    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }

    free(temp);
}

/* Delete a given value */
void deleteValue(int value)
{

    struct Node *temp = head;

    while (temp != NULL)
    {

        if (temp->data == value)
        {

            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);
            return;
        }

        temp = temp->next;
    }

    printf("Value not found\n");
}

/* Forward traversal */
void displayForward()
{

    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Backward traversal */
void displayBackward()
{

    struct Node *temp = head;

    if (temp == NULL)
        return;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main()
{

    insertFront(20);
    insertFront(10);
    insertEnd(30);
    insertEnd(40);

    printf("Forward: ");
    displayForward();

    printf("Backward: ");
    displayBackward();

    insertAfter(20, 25);

    printf("After insertion: ");
    displayForward();

    deleteFront();
    deleteEnd();
    deleteValue(25);

    printf("Final list: ");
    displayForward();

    return 0;
}