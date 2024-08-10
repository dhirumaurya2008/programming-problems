#include<bits/stdc++.h>

using namespace std;
int ceilSearch(int arr[], int start, int end, int key)
{

 if (key < arr[0])
    return start;
 if (key > arr[end])
    return -1;
 int mid = -1;
 int res = -1;
 while (start <= end)
 {
     mid = start + (end -start)/2;
     if (key < arr[mid])
     {
         end = mid -1;
         res = mid;
     }
     else if ( key > arr[mid])
     {
         start = mid +1;
     }
 }
 return res;
}

void merge(int arr1[], int arr2[], int n, int m) {

  if (n >m) {
    merge(arr2, arr1, m, n);
    return;
  }

  int low = 0;
  int high = n-1;
  int i, k;
  while (low<=high) {
    int ceilIndex = ceilSearch(arr1, low, high, arr2[0]);
    if (ceilIndex == -1)
        return;
    swap(arr1[ceilIndex], arr2[0]);
    low = ceilIndex+1;
    int first = arr2[0];
    // insertion sort is used here
    for (k = 1; k < m && arr2[k] < first; k++) {
      arr2[k - 1] = arr2[k];
    }
    arr2[k - 1] = first;
  }
}

int main() {
  int arr1[] = {10, 11, 12, 13};
  int arr2[] = {2,3,9};
  cout << "Before merge:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < 3; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;
  merge(arr1, arr2, 4, 3);
  cout << "After merge:" << endl;
  for (int i = 0; i < 4; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < 3; i++) {
    cout << arr2[i] << " ";
  }

}
