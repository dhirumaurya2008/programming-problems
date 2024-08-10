#include<stdio.h>

#if 0 /*Using Single Pointer*/
int main()
{
    int *arr= NULL;
    int r =3, c=4, count=0;

    arr = (int*)malloc(sizeof(int)*r*c);

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            arr[i*c+j] = count++;
           // printf("%d\n", arr[i*c+j]);
        }
    }

       for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("arr[%d][%d] = %d\n", i, j, arr[i*c+j]);
        }
    }
    return 0;
}
//#else /*Using Array of Pointer*/
int main()
{
    int r =3, c=4, count=0;
    int *arr[3]= {NULL};

    for(int i=0; i<r; i++)
    arr[i] = (int*)malloc(sizeof(int)*c);

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            //arr[i*c+j] = count++;
            arr[i][j] = count++;
           // printf("%d\n", arr[i*c+j]);
        }
    }

       for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
    return 0;
}
#else /*Using Pointer to Pointers*/
int main()
{
    int r =3, c=4, count=0;
    int **arr = NULL;

    (arr) = (int**)malloc(sizeof(int*)*r);
    for(int i=0; i<r; i++)
    {
        arr[i] = (int*)malloc(sizeof(int)*c);

    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            //arr[i*c+j] = count++;
            arr[i][j] = count++;
           // printf("%d\n", arr[i*c+j]);
        }
    }

       for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
    return 0;
}

#endif
