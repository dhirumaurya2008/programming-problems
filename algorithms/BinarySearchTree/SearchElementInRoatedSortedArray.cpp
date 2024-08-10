/*
An element in a sorted array can be found in O(log n) time via binary search.
But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand.
So for instance, 1 2 3 4 5 might become 3 4 5 1 2. Devise a way to find an element in the rotated array in O(log n) time.
*/

#include<iostream>
using namespace std;
int findMinElementIndex(int arr[], int start, int end)
{
    int size = end +1;
    int mid = -1;

    int next = -1;
    int prev = -1;

    while (start <=end)
    {
        mid = start + (end -start)/2;
        next = (mid +1) % size;
        prev = (mid + size -1) %size;

        if ((arr[mid] < arr[prev]) && (arr[mid] < arr[next]))
        {
            return mid;
        }
        else if (arr[start] <= arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid -1;
        }
    }
    return mid;
}

int binarySearch(int arr[], int start, int end, int key)
{
    int mid = -1;
    while (start <= end)
    {
        mid = start + (end -start)/2;

        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
        {
            end = mid -1;
        }
        else
            start = mid +1;
    }
    return mid;

}
int search(int arr[], int start, int end, int key)
{
   int minIdex = findMinElementIndex(arr, start, end);
   cout << " minIndex " << minIdex << endl;
   if (arr[minIdex] == key)
    return minIdex;
   else if ((key > arr[start]) && (key < arr[minIdex-1]))
   {
      return binarySearch(arr, start, minIdex-1, key);
   }
   else
   {
      return binarySearch(arr, minIdex+1, end, key);
   }

   return -1;

}
// Driver program
int main()
{
    int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    int i = search(arr, 0, n - 1, key);

    if (i != -1)
        cout << "Index: " << i << endl;
    else
        cout << "Key not found";
}
