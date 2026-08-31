/*
==================================================
        1. Write a menu-driven C Program to implement the following in 1-D array:
           a. Sum of even and odd numbers
             b. The sum of prime number

==================================================
*/

// Menu-Driven Program:
// A menu-driven program is a program that displays a list of options
// (menu) to the user.

#include <stdio.h>

void inputArray(int arr[], int s)
{
    for (int i = 0; i <= s; i++)
    {
        printf("Enter %d element:", i + 1);
        scanf("%d", &arr[i]);
    }
}
void PrintArray(int arr[], int s)
{
    printf("Element:");
    for (int i = 0; i <= s; i++)
    {
        printf("%d  ", arr[i]);
    }

    printf("\n Index :");

    for (int i = 0; i <= s; i++)
    {
        printf("%d  ", i + 1);
    }
}


void SumOfOdd(int arr[], int s)
{
    int sum = 0;
    for (int i = 0; i <= s; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sum = sum + arr[i];
        }
    }
    printf("\n Your sum of odd number is :%d", sum);
}

void SumOfEven(int arr[], int s)
{
    int sum = 0;
    for (int i = 0; i <= s; i++)
    {
        if (arr[i] % 2 != 0)
        {
            sum = sum + arr[i];
        }
    }
    printf("\n Your sum of Even number is :%d", sum);
}


void SumOfPrime(int arr[], int s)
{
    int sum = 0;

    printf("\n Your sum of Prime number is :%d", sum);
}




int main()
{
    int s;
    printf("Enter your size of array:");
    scanf("%d", &s);
    int arr[s];

    inputArray(arr, s);
    PrintArray(arr, s);
    SumOfOdd(arr, s);
    SumOfEven(arr, s);
    return 0;
}
