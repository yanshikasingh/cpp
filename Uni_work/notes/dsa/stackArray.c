#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

// Pop
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

// Peek
void peek()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element = %d\n", stack[top]);
    }
}

// Display
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack elements:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

// Is Empty
void isEmpty()
{
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Stack is not Empty\n");
}

// Is Full
void isFull()
{
    if (top == MAX - 1)
        printf("Stack is Full\n");
    else
        printf("Stack is not Full\n");
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    peek();

    pop();

    display();

    isEmpty();
    isFull();

    return 0;
}