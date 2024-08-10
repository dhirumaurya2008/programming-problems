/*Given an array of integers sorted in ascending order, and a target value,
find the element in the array that has minimum difference with the target value.*/

#include<iostream>

using namespace std;

int findMinDiffElements(const vector<int>& arr, int key) {
    if (key < arr[0]) {
      return arr[0];
    }
    if (key > arr[arr.size() - 1]) {
      return arr[arr.size() - 1];
    }

    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (key < arr[mid]) {
        end = mid - 1;
      } else if (key > arr[mid]) {
        start = mid + 1;
      } else {
        return arr[mid];
      }
    }

    // at the end of the while loop, 'start == end+1'
    // we are not able to find the element in the given array
    // return the element which is closest to the 'key'
    if ((arr[start] - key) < (key - arr[end])) {
      return arr[start];
    }
    return arr[end];
  }


int main()
{
    int arr[] = {2, 5, 10, 12, 15};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << " Min diff Elements " << (findMinDiffElements(arr, 0, size-1, 11));
    return 0;
}
