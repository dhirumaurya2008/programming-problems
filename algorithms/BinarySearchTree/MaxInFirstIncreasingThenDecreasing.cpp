/*
Find the maximum element in an array which is first increasing and then decreasing
*/
#include<iostream>
using namespace std;

int maxInBitonic(int arr[], int start, int end)
{
    int mid = -1;

    while (start <= end)
    {
        mid = start + (end -start)/2;
        if ( (arr[mid-1] > arr[mid]) && (arr[mid+1] > arr[mid]))
            return arr[mid];
        else if (arr[mid-1] > arr[mid])
            end = mid -1;
        else
            start = mid +1;
    }
    return (mid == -1)?mid:arr[mid];
}
/*Educative*/
 static int findMax(const vector<int>& arr) {
    int start = 0, end = arr.size() - 1;
    while (start < end) {
      int mid = start + (end - start) / 2;
      if (arr[mid] > arr[mid + 1]) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }

    // at the end of the while loop, 'start == end'
    return arr[start];
  }

int main()
{
    int arr[] = { 1, 3, 50, 10, 9, 7, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The maximum element is "
         << maxInBitonic(arr, 0, n - 1);
    return 0;
}
