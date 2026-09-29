#include <stdio.h>
#include <stdlib.h>

struct mydatatype
{
    int total_size;
    int used_size;
    int *ptr;
};

struct mydatatype s1;
struct mydatatype s2;

void createarray(struct mydatatype *first, int tsize, int usize)
{

    (*first).total_size = tsize;
    first->used_size = usize;

    first->ptr = (int *)malloc(tsize * sizeof(int)); // memory created in heap
}

void addarray(struct mydatatype *first)
{
    for (int i = 0; i < first->used_size; i++)
    {
        printf("\nenter your element of array:");
        scanf("%d", &(first->ptr)[i]);
    }

    printf(" your element of array:");
    for (int i = 0; i < first->used_size; i++)
    {
        printf(" %d ", (first->ptr)[i]);
    }
}

void show(struct mydatatype *first)
{
    printf(" \nyour element of array:");
    for (int i = 0; i < first->used_size; i++)
    {
        printf(" %d ", (first->ptr)[i]);
    }
}

void cleanup()
{

    printf("\nProgram is ending...");

    free(s1.ptr);
    free(s2.ptr);

    s1.ptr = NULL;
    s2.ptr = NULL;

    printf("\nMemory released automatically!\n");
}

void InsertionArray(struct mydatatype *first, int insertion, int element)
{
    int insertions = insertion, elements = element, temp = 0;
    // temp = (first->ptr)[insertions];
    // (first->ptr)[insertions] = elements;

    for (int i = first->used_size; i > insertions; i--)
    {
        first->ptr[i] = first->ptr[i - 1];
    }

    first->used_size++;
    (first->ptr)[insertions] = elements;
}

void deleteArray(struct)

    int main()
{
    //  struct mydatatype s1;
    //   struct mydatatype s2;

    atexit(cleanup);
    s1.total_size = 10;
    s1.used_size = 9;
    printf("total size: %d", s1.total_size);
    createarray(&s2, 10, 5);
    printf("\nthe total size of s2:%d", s2.total_size);
    addarray(&s2);
    InsertionArray(&s2, 1, 10);
    show(&s2);
}