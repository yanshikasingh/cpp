#include <stdio.h>

#define MAX 100

struct PriorityQueue
{
    int data;
    int priority;
};

struct PriorityQueue queue[MAX];

int size = 0;

// Insert
void enqueue(int value, int priority)
{
    int i;

    if (size == MAX)
    {
        printf("Queue Overflow\n");
        return;
    }

    i = size - 1;

    // Shift lower priority elements
    while (i >= 0 && queue[i].priority > priority)
    {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1].data = value;
    queue[i + 1].priority = priority;

    size++;

    printf("%d inserted with priority %d\n", value, priority);
}

// Delete highest priority
void dequeue()
{
    int i;

    if (size == 0)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d deleted\n", queue[0].data);

    for (i = 0; i < size - 1; i++)
    {
        queue[i] = queue[i + 1];
    }

    size--;
}

// Peek
void peek()
{
    if (size == 0)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Highest Priority Element = %d\n", queue[0].data);
    }
}

// Display
void display()
{
    int i;

    if (size == 0)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            printf("Data = %d  Priority = %d\n",
                   queue[i].data,
                   queue[i].priority);
        }
    }
}

int main()
{
    enqueue(10, 3);
    enqueue(20, 1);
    enqueue(30, 2);
    enqueue(40, 1);

    display();

    peek();

    dequeue();

    display();

    return 0;
}