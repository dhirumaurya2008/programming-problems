/*
Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands.
The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at
the correct position in the sorted part.
*/
#include<bits/stdc++.h>
using namespace std;

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


/*The idea is to divide the array into 2 parts, left part should be sorted and right unsorted.
*/
void insertionSort(int arr[], int size)
{
    for (int i=1; i<size; i++)
    {
        int hole = i;
        int holeValue = arr[hole];

        while ( (hole > 0) && (arr[hole-1] > holeValue))
        {
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = holeValue;
    }
}
/* Driver code */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Printing elements before sorting" << endl;
    printArray(arr, n);

    insertionSort(arr, n);
     cout << "Printing elements After sorting" << endl;
    printArray(arr, n);

    return 0;
}
