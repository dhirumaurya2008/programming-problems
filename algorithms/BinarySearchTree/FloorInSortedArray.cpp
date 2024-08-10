/*
Given a sorted array and a value x, the floor of x is the largest element in array smaller than or equal to x.
Write efficient functions to find floor of x.
*/

#include<iostream>
using namespace std;

int floorSearch(int arr[], int start, int end, int key)
{
  int mid = -1;
  int res = -1;
  while (start <= end)
  {
     mid = start + (end - start)/2;
     if (key == arr[mid])
        return mid;
     else if (key < arr[mid])
     {
        end = mid -1;
     }
     else if (key > arr[mid])
     {
         start = mid + 1;
         res = mid;
     }
  }
  return res;
}

/* Driver program to check above functions */
int main()
{
    int arr[] = { 1, 2, 4, 6, 10, 12, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    int index = floorSearch(arr, 0, n - 1, x);
    if (index == -1)
        cout<< "Floor of " <<x <<" doesn't exist in array ";
    else
        cout<<"Floor of "<< x <<" is " << arr[index];
    return 0;
}
