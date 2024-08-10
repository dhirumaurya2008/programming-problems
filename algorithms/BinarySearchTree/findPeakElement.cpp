/*
Given an array of integers. Find a peak element in it.
An array element is a peak if it is NOT smaller than its neighbours.
For corner elements, we need to consider only one neighbour.
*/
#include<iostream>
using namespace std;
int findPeak(int arr[], int size)
{
    int start = 0;
    int end = size -1;
    int mid = -1;

    while (start <= end )
    {
       mid = start + (end -start) /2 ;

       if ( (mid > 0) && (mid < end))
       {
           if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            return arr[mid];
           else if (arr[mid+1] > arr[mid])
            start = mid +1;
           else
            end = mid -1;
       }
       else if (mid == 0)
       {
           if (arr[0] > arr[1])
                return arr[0];
           else
            return arr[1];
       }
       else if (mid == size-1)
       {
           if (arr[size-1] > arr[size-2])
            return arr[size-1];
           else
            return arr[size-2];
       }
    }
    return -1;
}
int main()
{
    //int arr[] = { 1, 3, 20, 4, 1, 0 };
    int arr[] = { 100, 30, 20, 4, 1, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Index of a peak point is "
         << findPeak(arr, n);
    return 0;
}
