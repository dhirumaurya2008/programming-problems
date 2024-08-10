/*Given an array arr[] of size n containing integers.
The problem is to find the length of the longest sub-array having sum equal to the given value k.
*/
#include<bits/stdc++.h>
using namespace std;

int lenLargestSubArray(int arr[], int size, int k)
{
    int i = 0, j = 0;
    int sum = 0, maxWinSize = INT_MIN;
    while (j<size)
    {
        sum += arr[j];

        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            int windowSize = j-i+1;
            maxWinSize = max(maxWinSize, windowSize);
            j++;
        }
        else if (sum > k)
        {
            while (sum>k)
            {
                sum = sum - arr[i];
                i++;
            }
            j++;
        }
    }
    return maxWinSize;
}

int main()
{
    int arr[] = {10, 5, 2, 7, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 15;
    cout << "Max window Length = "
         << lenLargestSubArray(arr, n, k);
    return 0;
}
