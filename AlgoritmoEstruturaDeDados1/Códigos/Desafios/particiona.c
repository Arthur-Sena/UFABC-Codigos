#include <stdio.h>
#include <stdlib.h>

void printVector(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void particiona(int *arr, int n, int p)
{

    int pivot = arr[p];
    arr[p] = arr[n-1];
    arr[n-1] = pivot;
    p = n-1;

    int pm = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]<=arr[p])
        {
            pm++;
            if (i != pm)
            {
                int aux = arr[i];
                arr[i] = arr[pm];
                arr[pm] = aux;
            }
        }
    }
}

int main()
{
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);
    int *arr = (int *) malloc (n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    particiona(arr, n, p);

    printVector(arr, n);
    return 0;
}