#include <stdio.h>

int main()
{
    int size1;
    scanf("%d", &size1);
    char str1[size1+1];
    scanf("%s", str1);
    int size2;
    scanf("%d", &size2);
    char str2[size2+1];
    scanf("%s", str2);

    int index1 = 0, index2 = 0;

    while(index1 < size1 && index2 < size2)
    {
        if (str1[index1] <= str2[index2])
        {
            printf("%c",str1[index1]);
            index1++;
        } 
        else if (str1[index1] > str2[index2])
        {
            printf("%c", str2[index2]);
            index2++;
        }
    }

    while(index1 < size1)
    {
        printf("%c",str1[index1]);
        index1++;
    }

    while(index2 < size2)
    {
        printf("%c", str2[index2]);
        index2++;
    }
    printf("\n");
    return 0;
}

    //int i = 0;
    //while (idStringA < sizeStringA || idStringB < sizeStringB) {
    //    if (idStringA < sizeStringA) {
    //        stringIntercalada[i] = stringA[idStringA];
    //        i++;
    //        idStringA++;
    //    }
    //    if (idStringB < sizeStringB) {
    //        stringIntercalada[i] = stringB[idStringB];
    //        i++;
    //        idStringB++;
    //    }
    //}