#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    int key = 60;

    // Linear Search
    int result1 = linearSearch(arr, n, key);

    if (result1 != -1)
        printf("Linear Search: Element found at index %d\n", result1);
    else
        printf("Linear Search: Element not found\n");

    // Binary Search
    int result2 = binarySearch(arr, n, key);

    if (result2 != -1)
        printf("Binary Search: Element found at index %d\n", result2);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}