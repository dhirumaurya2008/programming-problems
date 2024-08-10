/*Count number of occurrences (or frequency) in a sorted array
Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[].
 Expected time complexity is O(Logn)
*/


#include<iostream>
#include<cstdio>

using namespace std;
int firstIndex(int arr[], int key, int size)
{
   int start = 0;
   int end = size -1;
   int mid = -1;
   int res = -1;
   while (start <= end)
   {
       mid = start + (end -start)/2;
       if (key == arr[mid])
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
           start = mid +1;
       }
   }
   return res;
}

int lastIndex(int arr[], int key, int size)
{
int start = 0;
   int end = size -1;
   int mid = -1;
   int res = -1;
   while (start <= end)
   {
       mid = start + (end -start)/2;
       if (key == arr[mid])
       {
           res = mid;
           start = mid +1;
       }
       else if (key < arr[mid])
       {
           end = mid -1;
       }
       else
       {
           start = mid +1;
       }
   }
   return res;
}


int count(int arr[], int key, int size)
{
   int first = firstIndex(arr, key, size);
   int last  = lastIndex(arr, key, size);
   if (first == -1 || last == -1)
    return 0;
   return (last - first + 1);
}
/* driver program to test above functions */
int main()
{
  int arr[] = {1, 2, 2, 3, 3, 3, 3};
 // int x =  3;  // Element to be counted in arr[]
   int x =  7;  // Element to be counted in arr[]
  int n = sizeof(arr)/sizeof(arr[0]);
  int c = count(arr, x, n);
  printf(" %d occurs %d times ", x, c);
  return 0;
}
