/*Given an array of integers and a number k, find the maximum sum of a subarray of size k.
Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700
*/
#include<bits/stdc++.h>
using namespace std;

/*Main Point*/

int maxSumOfSubArrOfSizeK(int arr[], int size, int k)
{
    int j = 0;
    int i = 0;
    int sumMax = INT_MIN;
    int sum = 0;
    while (j <size)
    {
       sum += arr[j];
        /*Windows size (j-1+1)*/
        if ((j -i +1) < k)
        {
            j++;
        }
        else if ((j-i + 1) == k)
        {

            sumMax = max (sumMax, sum);
            sum = sum - arr[i];
            i++; j++;
        }
    }

    return sumMax;

}


int main()
{
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSumOfSubArrOfSizeK(arr, n, k);
    return 0;
}
