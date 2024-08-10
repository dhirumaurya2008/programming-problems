#include<iostream>
using namespace std;

int reversBinarySearch(int arr[], int N, int key)
{
    int start = 0;
    int end = N-1;
    int mid = -1;

    while (start <= end)
    {
        mid = start + ( end - start ) / 2;

        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            start = mid +1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return mid;
}
int main()
{
    int arr[] = { 5, 4, 3, 2, 1 };
    int N = sizeof(arr) / sizeof(arr[0]);
    int X = 1;
    cout << reversBinarySearch(arr, N, X);
    return 0;
}
