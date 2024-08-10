#if 0
arr[] = {10, 80, 30, 90, 40, 50, 70}
#endif
#include<iostream>
using namespace std;

int split(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high], pIndex = low;
        for (int i = low; i<high; i++)
        {
            if (arr[i] < pivot) {
                swap(arr[i], arr[pIndex]);
                pIndex = pIndex + 1;
            }
        }
        swap(arr[pIndex], pivot);
        return pIndex;
    }
    return low;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pIndex = split(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, high);
    }
}
int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    //int arr[] = {1,1,0,1,0,1,1,0,0,0,0,1};
    int low = 0, high = sizeof(arr)/sizeof(arr[0]);
    cout << "Array element before sorting using Quick Sort " << endl;

    for (int i = 0; i < high; i++)
        cout << arr[i] << " " ;

    quickSort(arr, low, high-1);

    cout << "\nArray element after sorting using Quick Sort " << endl;

    for (int i = 0; i < high; i++)
        cout << arr[i] << " " ;
}
