#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *rear = NULL;

/* Insert at end */
void insertEnd(int value)
{

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    /* Empty list */
    if (rear == NULL)
    {
        rear = newNode;
        rear->next = rear;
        return;
    }

    newNode->next = rear->next;
    rear->next = newNode;
    rear = newNode;
}

/* Insert at front */
void insertFront(int value)
{

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (rear == NULL)
    {
        rear = newNode;
        rear->next = rear;
        return;
    }

    newNode->next = rear->next;
    rear->next = newNode;
}

/* Display */
void display()
{

    struct Node *cur;

    if (rear == NULL)
    {
        printf("List is empty\n");
        return;
    }

    cur = rear->next;

    do
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    } while (cur != rear->next);

    printf("(back to first)\n");
}

/* Delete front */
void deleteFront()
{

    struct Node *cur;

    if (rear == NULL)
    {
        printf("List is empty\n");
        return;
    }

    cur = rear->next;

    /* Only one node */
    if (cur == rear)
    {
        rear = NULL;
        free(cur);
        return;
    }

    rear->next = cur->next;
    free(cur);
}

/* Delete end */
void deleteEnd()
{

    struct Node *cur, *prev;

    if (rear == NULL)
    {
        printf("List is empty\n");
        return;
    }

    cur = rear->next;
    prev = rear;

    /* Only one node */
    if (cur == rear)
    {
        rear = NULL;
        free(cur);
        return;
    }

    while (cur != rear)
    {
        prev = cur;
        cur = cur->next;
    }

    prev->next = rear->next;
    rear = prev;

    free(cur);
}

/* Delete given value */
void deleteValue(int value)
{

    struct Node *cur, *prev;

    if (rear == NULL)
    {
        printf("List is empty\n");
        return;
    }

    prev = rear;
    cur = rear->next;

    do
    {

        if (cur->data == value)
        {

            /* Only one node */
            if (cur == prev)
            {
                rear = NULL;
            }
            else
            {
                prev->next = cur->next;

                if (cur == rear)
                    rear = prev;
            }

            free(cur);
            return;
        }

        prev = cur;
        cur = cur->next;

    } while (cur != rear->next);

    printf("Value not found\n");
}

int main()
{

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    printf("Circular list: ");
    display();

    insertFront(5);

    printf("After front insertion: ");
    display();

    deleteFront();

    printf("After deleting front: ");
    display();

    deleteEnd();

    printf("After deleting end: ");
    display();

    deleteValue(20);

    printf("After deleting 20: ");
    display();

    return 0;
}