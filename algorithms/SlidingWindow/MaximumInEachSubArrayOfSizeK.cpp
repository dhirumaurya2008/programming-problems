/*Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.
*/

#include<bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int size, int k)
{
    list<int> l;
    int i = 0, j = 0;
    vector<int> vec;
    while (j<size)
    {
        /*Calculation step*/
        while ((l.size()>0) && (l.back() < arr[j]))
        {
            l.pop_back();
        }
        l.push_back(arr[j]);

        /*Window not HIt*/
        if (j-i+1 <k)
            j++;
        else if (j-i+1 == k) /*Window hit case*/
        {
            /*Get Ans*/
            vec.push_back(l.front());

            /*slide the window*/
            if (l.front() == arr[i])
                l.pop_front();
            i++, j++;
        }

    }

    for (int i=0; i<vec.size(); i++)
        cout << vec[i] << " " ;

}

int main()
{
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}
