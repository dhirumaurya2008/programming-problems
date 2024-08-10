/*
Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of
 an element x in the given array. Given a sorted array with possibly duplicate elements, the task is to find indexes
 of first and last occurrences of an element x in the given array.
*/
#include<iostream>
#include<cstdio>
using namespace std;

int first(int arr[], int start, int end, int key)
{
    int mid = -1;
    int res = -1;
    while (start <= end) {
        mid = start + (end - start)/2;

        if ( key == arr[mid])
        {
            res = mid;
            end = mid -1;
        }
        else if (key < arr[mid])
        {
            end = mid -1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}

int last(int arr[], int start, int end, int key)
{
    int mid = -1;
    int res = -1;
    while (start <= end) {
        mid = start + (end - start)/2;

        if ( key == arr[mid])
        {
            res = mid;
            start = mid + 1;

        }
        else if (key < arr[mid])
        {
            end = mid -1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}
// Driver Code
int main(void)
{
      int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(int);

    int x = 6;
    printf("First Occurrence = %d\t",
           first(arr, 0, n - 1, x));
    printf("\nLast Occurrence = %d\n",
           last(arr, 0, n - 1, x));

    return 0;
}
