/*
Given a bitonic sequence of n distinct elements,
write a program to find a given element x in the bitonic sequence in O(log n) time.
A Bitonic Sequence is a sequence of numbers that is first strictly increasing then after a point strictly decreasing.
*/
#include<bits/stdc++.h>
using namespace std;
int findBitonicPoint(int arr[], int start, int end)
{
    int mid = INT_MIN;

    while (start <= end)
    {
        mid = start + (end - start)/2;

        if ((arr[mid-1] > arr[mid]) && (arr[mid+1] > arr[mid]))
            return mid;
        else if(arr[mid-1] > arr[mid])
            end = mid -1;
        else
            start = mid +1;
    }
    return mid;
}

int searchBitonic(int arr[], int size, int key, int index)
{
    if (index == INT_MIN)
        return -1;
    if (key == arr[index])
        return index;
    int start , end ;

    if ( (key >= arr[0]) && (key <=arr[index-1]))
    {
        start = 0;
        end = index-1;
    }
    else if ((key >= arr[index+1]) && (key <=arr[end]))
    {
        start = index +1;
        end = end;
    }
    int mid = -1;
    while (start <= end)
    {
        mid = start + (end - start)/2;

        if (key == arr[mid])
            return mid;
        else if (arr[mid] < key)
            start = mid +1;
        else
            end = mid -1;
    }

    return mid;
}
// Driver code
int main()
{
    int arr[] = { -8, 1, 2, 3, 4, 5, -2, -3 };
    int key = -2;
    int n, l, r;
    n = sizeof(arr) / sizeof(arr[0]);
    l = 0;
    r = n - 1;
    int index;

    // Function call
    index = findBitonicPoint(arr, l, r);

    int x = searchBitonic(arr, n, key, index);

    if (x == -1)
        cout << "Element Not Found" << endl;
    else
        cout << "Element Found at index " << x << endl;

    return 0;
}
