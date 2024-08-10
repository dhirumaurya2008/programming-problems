/*
Problem - Given a k–sorted array that is almost sorted such that each of the n elements may be misplaced by no more than k positions
 from the correct sorted order. Find a space-and-time efficient algorithm to sort the array.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void sortKSortedArray(vector<int> &arr, int k)
{
  /*create a min heap*/
  priority_queue<int , vector<int>, greater<int>> pq;

  /*Push first k element into the heap*/
  for(int i=0; i<=k; i++){
    pq.push(arr[i]);
  }

  /*Now get the top and push next element into it from k+1 to arr.size()-1*/
  int unsigned index = 0;
  for(int i= k+1; i<arr.size();i++) {
    arr[index++] = pq.top();
    pq.pop();
    pq.push(arr[i]);
  }

  while (pq.size() > 0) {
    arr[index++] = pq.top();
    pq.pop();
  }
}

int main()
{
    vector<int> nums = { 1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
    int k = 2;

    cout << "Array element before calling sortKSortedArray " << endl;
    for (int i: nums) {
        cout << i << " ";
    }
    sortKSortedArray(nums, k);

    cout << "\n\n" ;
    cout << "Array element after sortKSortedArray call " << endl;
    // print the sorted array
    for (int i: nums) {
        cout << i << " ";
    }

    return 0;
}
