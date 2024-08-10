#include<iostream>
#include<cstdio>
using namespace std;

int binarySearch(int arr[], int start, int end, int key)
{
    int mid = -1;
    while (start <= end)
    {
        mid = start + (end - start)/2;

        if (key == arr[mid])
        {
            return mid;
        }
        else if (((mid-1) >= start) && (key == arr[mid-1]))
        {
            return mid-1;
        }
        else if (((mid+1) <= end) && (key == arr[mid+1]))
        {
            return mid+1;
        }

        if (key < arr[mid])
        {
            end = end -2;
        }
        else
        {
            start = mid +2;
        }
    }
    return mid;
}
// Driver Code
int main(void)
{
//int arr[] = {3, 2, 10, 4, 40};
int arr[]= {10, 3, 40, 20, 50, 80, 70};
int n = sizeof(arr) / sizeof(arr[0]);
//int x = 4;
int x = 40;
int result = binarySearch(arr, 0, n - 1, x);
(result == -1) ? printf("Element is not present in array")
               : printf("Element is present at index %d",
                         result);
return 0;
}
