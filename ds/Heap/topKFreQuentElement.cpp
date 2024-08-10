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

void print_N_mostFrequentNumber(int arr[], int arr_size, int k)
{
   unordered_map<int, int> mp;
   for (int i =0; i< arr_size; i++) {
     mp[arr[i]]++;
   }

    cout << "\n Elements frequencies are " << endl;
    for (auto i = mp.begin(); i != mp.end(); i++) {
      cout << "[ " << i->first << " , " << i->second << " ]" ;
   }
   priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int>> > pq;

   for (auto i = mp.begin(); i != mp.end(); i++) {
    pq.push({i->second, i->first});
    if (pq.size() > k){
        pq.pop();
    }
   }

   cout << "\n Top " << k << " Elements Are :- " << endl;
   while (pq.size() > 0){
    cout << pq.top().second << " ";
    pq.pop();
   }

}

// Driver program to test above
int main()
{
    int arr[] = { 3, 1, 4, 4, 5, 2, 6, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    print_array(arr, n, "Input arrays are");
    print_N_mostFrequentNumber(arr, n, k);
    return 0;
}

