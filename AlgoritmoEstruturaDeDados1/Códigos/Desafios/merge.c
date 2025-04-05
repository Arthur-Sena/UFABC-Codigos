#include <stdio.h>
#include <stdlib.h>

void printVector(int *vector, int size) {
    for (int i = 0; i < size; i++)
        if (i != size-1)
            printf("%d ", vector[i]);
        else 
            printf("%d\n", vector[i]);
}

void merge(int *vector, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftVector = (int *)malloc(n1 * sizeof(int));
    int *rightVector = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        leftVector[i] = vector[left + i];

    for (int i = 0; i < n2; i++)
        rightVector[i] = vector[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftVector[i] <= rightVector[j]) {
            vector[k] = leftVector[i];
            i++;
        } else {
            vector[k] = rightVector[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vector[k] = leftVector[i];
        i++;
        k++;
    }

    while (j < n2) {
        vector[k] = rightVector[j];
        j++;
        k++;
    }

    free(leftVector);
    free(rightVector);
}

void mergeSort(int *vector, int size, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(vector, size, left, mid);
        mergeSort(vector, size, mid + 1, right);

        printVector(vector, size);
        merge(vector, left, mid, right);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    if (N == 0) {
        printf("\n");
        return 0;
    }

    int *vector = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        scanf("%d", &vector[i]);

    printVector(vector, N);
    mergeSort(vector, N, 0, N - 1);
    printVector(vector, N);

    free(vector);

    return 0;
}
