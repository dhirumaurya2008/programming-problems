/*
Order-Agnostic Binary Search is a modified version of Binary Search algorithm.
Here in this modified binary search comes with one more condition checking.
The intuition behind this algorithm is what if the order of the sorted array is not given.
 So here check that the value of the first element is greater or smaller than the last element.
*/
#include<iostream>
using namespace std;
#define IS_ACCENDING(start , end) ((start < end)? 1 : 0)

int binarySearch(int arr[], int start, int end, int key)
{
    int mid = -1;
    int isAssending = (arr[start] < arr [end]) ? 1 : 0;
    while (start <= end)
    {
        mid = start + ( end - start )/2;

        if (key == arr[mid])
        {
            return mid;
        }
        else if ( key < arr[mid])
        {
            if ( isAssending )
                end = mid -1;
            else
                start = mid + 1;
        }
        else
        {
            if ( isAssending )
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return mid;
}
// Driver Code
int main(void)
{
    int arr[] = { 40, 10, 5, 2, 1 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Reverse order" << endl;
    cout << binarySearch(arr, 0, n - 1, x) << endl;
    {
        cout << "Regular order" << endl;
            int arr[] = {1,2,5,10,40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << binarySearch(arr, 0, n - 1, x);
    }

    return 0;
}
