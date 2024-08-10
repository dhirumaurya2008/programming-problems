#include<bits/stdc++.h>
using namespace std;
// Driver Code
int getInvCount(int arr[], int n)
{
    int inverCnt = 0;

    for (int i = 0; i<n;i++)
    {
        for (int j=i+1; j<n; j++)
        {

            if (arr[i] > arr[j])
               inverCnt++;
        }
    }
    return inverCnt;
}

int merge(int arr[], int low, int mid, int high)
{
    int nLeft = mid - low +1;
    int nRight = high - mid;

    int arrLeft[nLeft], arrRight[nRight];

    for (int i=0; i<nLeft; i++)
    {
        arrLeft[i] = arr[low+i];
    }

    for (int i=0; i<nRight; i++)
    {
        arrRight[i] = arr[mid+1+i];
    }

    int i =0, j=0, k = low, inverCnt = 0;
    while ( (i <nLeft) && (j <nRight))
    {
        if (arrLeft[i] <= arrRight[j])
        {
            arr[k] = arrLeft[i];
            i++; k++;
        }
        else
        {
            inverCnt += nLeft - i;
            arr[k] = arrRight[j];
            j++; k++;
        }
    }
    while (i <nLeft)
    {
         arr[k] = arrLeft[i];
          i++; k++;
    }

    while (j <nRight)
    {
        arr[k] = arrRight[j];
        j++; k++;
    }
    return inverCnt;
}

int mergeSort(int arr[], int low, int high)
{
    int mid = -1, inverCnt = 0;
    if (low < high) {
        mid = low + (high - low)/2;
        inverCnt += mergeSort(arr, low, mid);
        inverCnt += mergeSort(arr, mid+1, high);
        inverCnt += merge(arr, low, mid, high);
    }
    return inverCnt;
}

int getInvCountMergeSort(int arr[], int n)
{
    return mergeSort(arr, 0, n-1);
}

int main()
{
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " Number of inversions are "
         << getInvCountMergeSort(arr, n);
    return 0;
}
