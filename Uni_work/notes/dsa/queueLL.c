#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

/* ENQUEUE */
void enqueue(int value)
{

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    /* Empty queue */
    if (rear == NULL)
    {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

/* DEQUEUE */
void dequeue()
{

    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;

    printf("Deleted: %d\n", temp->data);

    front = front->next;

    /* Queue became empty */
    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
}

/* PEEK */
void peek()
{

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Front = %d\n", front->data);
}

/* DISPLAY */
void display()
{

    struct Node *temp = front;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Queue: ");
    display();

    peek();

    dequeue();

    printf("After DEQUEUE: ");
    display();

    return 0;
}