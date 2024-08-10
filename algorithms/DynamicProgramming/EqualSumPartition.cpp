/*Partition problem is to determine whether a given set can be partitioned into two subsets
such that the sum of elements in both subsets is the same.
arr[] = {1, 5, 11, 5}
Output: true
The array can be partitioned as {1, 5, 5} and {11}

arr[] = {1, 5, 3}
Output: false
The array cannot be partitioned into equal sum sets.
 */


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool isSubSetPresentForGivenSum(int arr[], int size, int sum)
{
    bool t[size+1][sum+1];

    memset(t, false, sizeof(t));

    for (int j=0; j<sum+1; j++)
        t[0][j] = false;
    for (int i=0; i<size+1; i++)
        t[i][0] = true;

    for(int i=1; i<size+1; i++)
    {
        for (int j=1; j<sum+1; j++)
        {
            if (arr[i-1] <=j)
            {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else
                t[i][j] = t[i-1][j];

        }
    }

    return t[size][sum];
}

bool findPartiion(int arr[], int size)
{
    int sum = 0;
    /*Calculate sum if sum is odd then no way to form 2 equal partition, if even then there it may or may not*/
    for (int i=0; i<size; i++)
        sum += arr[i];

    if (sum % 2 == 1)
        return false;

    return isSubSetPresentForGivenSum(arr, size, sum/2);
}
int main()
{
    //int arr[] = { 3, 1, 1, 2, 2, 1 };
    //int arr[] = {1, 5, 11, 5};
    int arr[] = {1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets of equal "
                "sum";
    else
        cout << "Can not be divided into"
             << " two subsets of equal sum";
    return 0;
}
