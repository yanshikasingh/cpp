#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

/* PUSH */
void push(int value)
{

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;

    top = newNode;
}

/* POP */
void pop()
{

    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;

    printf("Deleted: %d\n", temp->data);

    top = top->next;

    free(temp);
}

/* PEEK */
void peek()
{

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top = %d\n", top->data);
}

/* DISPLAY */
void display()
{

    struct Node *temp = top;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{

    push(10);
    push(20);
    push(30);

    printf("Stack:\n");
    display();

    peek();

    pop();

    printf("After POP:\n");
    display();

    return 0;
}