#if 0
arr[] = {10, 80, 30, 90, 40, 50, 70}
#endif
#include<iostream>
using namespace std;

void mergeElement(int arr[], int low, int mid, int high)
{
  int nLeft = (mid - low + 1);
  int nRight = high - mid;

  int arrLeft[nLeft], arrRight[nRight];
  int i = 0, j = 0, k = 0;
  for (; i < nLeft; i++)
    arrLeft[i] = arr[low+i];

  for (; j < nRight; j++)
    arrRight[j] = arr[mid+j+1];
  i = 0; j = 0; k = low;

  while ((i<nLeft) && (j<nRight))
  {
      if (arrLeft[i] < arrRight[j])
        arr[k] = arrLeft[i++];
      else
        arr[k] = arrRight[j++];
      k++;
  }

  while (i < nLeft)
  {
     arr[k] = arrLeft[i++];
     k++;
  }

  while (j < nRight)
  {
     arr[k] = arrRight[j++];
     k++;
  }

}

void mergeSort(int arr[], int low, int high)
{
    if ( low < high)
    {
        int mid = low + (high - low)/2 ;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        mergeElement(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int low = 0, high = sizeof(arr)/sizeof(arr[0]);
    cout << "Array element before sorting using mergeSort " << endl;

    for (int i = 0; i < high; i++)
        cout << arr[i] << " " ;

    mergeSort(arr, low, high-1);

    cout << "\nArray element after sorting using mergeSort " << endl;

    for (int i = 0; i < high; i++)
        cout << arr[i] << " " ;
}
