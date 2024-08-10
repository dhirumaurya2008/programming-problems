/*
Given an array of n numbers and a positive integer k. The problem is to find k numbers with most occurrences, i.e.,
 the top k numbers having the maximum frequency. If two numbers have the same frequency then the larger number should be given preference.
 The numbers should be displayed in decreasing order of their frequencies. It is assumed that the array consists of k numbers with
 most occurrences.
Input:
arr[] = {3, 1, 4, 4, 5, 2, 6, 1},
k = 2
Output: 4 1
*/
#include<iostream>
#include<map>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int arr_size, string str)
{
    cout << " " << str << endl ;
    for (int i =0; i< arr_size; i++) {
        cout << " " << arr[i] ;
    }
}

void sortByFrequencyAndIndex(int arr[], int arr_size)
{
   unordered_map<int, pair<int, int>> mp;
   for (int i =0; i< arr_size; i++) {
         if (mp.find(arr[i]) != mp.end())
         {
             mp[arr[i]].first++;
         }
         else {

            mp[arr[i]] = {1, i};
         }
   }

   /*{value, {frequency, index}}*/

    cout << "\n Elements frequencies are " << endl;
    for (auto i = mp.begin(); i != mp.end(); i++) {
      cout << "[ " << i->first << " , " << (i->second).first << " , " << (i->second).second << " ]" ;
   }
   priority_queue<pair <pair<int, int>>> pq;

   for (auto i = mp.begin(); i != mp.end(); i++) {
      if (pq.size()> 0) {
        pq.push({i->second, i->first});
      }
   }

   cout << " Elements Are :- " << endl;
   while (pq.size() > 0){
    cout << "[ "<< pq.top().second << ", " << pq.top().first << " ]";
    pq.pop();
   }

}

// Driver program to test above
int main()
{
   int a[] = { 3, 3, 1, 1, 1, 8, 3, 6, 8, 7, 8 };
    int n = sizeof(a) / sizeof(a[0]);

    sortByFrequencyAndIndex(a, n);

    return 0;
}

