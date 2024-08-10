/*Given a sorted array consisting 0’s and 1’s. The problem is to find the index of first ‘1’ in the sorted array.
It could be possible that the array consists of only 0’s or only 1’s. If 1’s are not present in the array then print “-1”.
*/
#include<iostream>
using namespace std;

int indexOfFirstOne(int arr[], int start, int end)
{
    int mid = -1;
    int res = -1;
   while (start <= end)
   {
       mid = start + (end -start)/2;

       if (arr[mid] == 1)
       {
           res = mid;
           end = end -1;
       }
       else
       {
           start = mid +1;
       }
   }
   return res;
}

int main()
{
    int arr[] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << indexOfFirstOne(arr, 0, n - 1);
    return 0;
}
