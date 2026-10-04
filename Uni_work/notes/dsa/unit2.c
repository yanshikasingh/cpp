#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }

    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }

    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is Full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;

    if (isEmpty(q))
    {
        printf("This Queue is Empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }

    return a;
}

int main()
{
    struct queue q;

    q.size = 100;
    q.f = q.r = -1;

    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue elements
    enqueue(&q, 12);
    enqueue(&q, 15);

    // Check if queue is empty
    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue is not Empty\n");
    }

    // Dequeue elements
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));

    // Check again
    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue is not Empty\n");
    }

    return 0;
}