#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int key)
{
    int mid = -1;
    while (start <= end) {

        mid = start + (end -start)/2;

        if ( key == arr[mid])
            return mid;
        else if (key > arr[mid])
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

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}
