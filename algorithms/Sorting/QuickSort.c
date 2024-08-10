#include<stdio.h>

int partition(int arr[], int start, int end)
{
    if(start >= end)
        return start;

    int pIndex = start, pivot = arr[end], temp;

    for(int i=start; i<end; i++)
    {
        if(arr[i] <= pivot)
        {
           temp = arr[i];
           arr[i] = arr[pIndex];
           arr[pIndex++] = temp;
        }
    }

    temp = arr[end];
    arr[end] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex;

}
void quick_sort(int arr[], int start, int end)
{
    int pIndex=0;
    if(start < end)
    {
        pIndex = partition(arr, start, end);
        quick_sort(arr, start, pIndex-1);
        quick_sort(arr, pIndex+1, end);
    }
}

int main()
{

    int arr[]={45,67,20,45,6,5};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("Array before sorting\n");
    for(int i=0; i<arrSize; i++)
        printf("%d\t", arr[i]);
    quick_sort(arr, 0, arrSize-1);
    printf("\nArray After sorting\n");
    for(int i=0; i<arrSize; i++)
        printf("%d\t", arr[i]);


}
