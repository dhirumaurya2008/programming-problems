/*Consider an array of distinct numbers sorted in increasing order. The array has been rotated (clockwise) k number of times.
 Given such an array, find the value of k.
 */
#include <iostream>
#include <cstdio>
using namespace std;
 int minElementsIndex(int arr[], int start, int end)
 {
    int mid = -1;
    int size = end + 1;
    while (start <= end)
    {
        mid = start + (end - start)/2;
        int prev = (mid + (size) -1) % size;
        int next = (mid + 1) % size;
        printf(" prev : mid: next(%d: %d: %d)| arr[mid] = %d, arr[prev] = %d, arr[next] = %d \n", prev, mid, next, arr[mid], arr[prev], arr[next]);
        if ((arr[mid] < arr[prev]) && (arr[mid] < arr[next]))
        {
            return mid;
        }
        else if (arr[start] <= arr[mid] )
        {
             start = mid +1;

        }
        else if (arr[mid] <= arr[end])
        {
            end = mid -1;
        }
    }
    return -1;
 }
int countRotations(int arr[], int start, int end)
{
    int mid = -1;
    int size = end+1;
    int minEIndex =  minElementsIndex(arr, start, end);

    return ((size - minEIndex)% size);

}

// Driver code
int main()
{
    int arr[] = {18, 2, 3, 6, 12, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countRotations(arr, 0, n-1);
    return 0;
}
