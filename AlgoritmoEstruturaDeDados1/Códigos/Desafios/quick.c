#include <stdio.h>
#include <stdlib.h>

void printVector(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        if (i < n-1)
            printf("%d ", arr[i]);
        else
            printf("%d\n", arr[i]);
}

void change(int * v1, int * v2)
{
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

int particiona(int *arr, int n, int start, int end)
{
    int pm = start-1;
    for (int i = start; i < end; i++)
    {
        if (arr[i]<=arr[end])
        {
            pm++;
            change(&arr[i], &arr[pm]);
        }
        printVector(arr, n);
    }
    pm++;
    change(&arr[end], &arr[pm]);
    printVector(arr, n);
    return pm;
}

void quickSort(int *arr, int n, int start, int end)
{
    if (start<end)
    {
        int p = particiona(arr, n, start, end);
        quickSort(arr, n, start, p-1);
        quickSort(arr, n, p+1, end);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc (n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printVector(arr, n);

    quickSort(arr, n, 0, n-1);

    printVector(arr, n);
    free(arr);
    return 0;
}