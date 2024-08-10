/*
Given a sorted array and a value x, the ceiling of x is the smallest element in array greater than or equal to x,
and the floor is the greatest element smaller than or equal to x. Assume than the array is sorted in non-decreasing order.
Write efficient functions to find floor and ceiling of x.
*/
#include<iostream>
using namespace std;

int ceilSearch(int arr[], int start, int end, int key)
{
 int mid = -1;
 int res = -1;

 while (start <= end)
 {
     mid = start + (end -start)/2;

     if (key == arr[mid])
        return mid;
     else if (key < arr[mid])
     {
         end = mid -1;
         res = mid;
     }
     else if ( key > arr[mid])
     {
         start = mid +1;
     }
 }
 return res;
}
// Driver Code
int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
   // int x = 20;
   int x = 9;
    int index = ceilSearch(arr, 0, n-1, x);
    if(index == -1)
        cout << "Ceiling of " << x
             << " doesn't exist in array ";
    else
        cout << "ceiling of " << x
             << " is " << arr[index];

    return 0;
}
