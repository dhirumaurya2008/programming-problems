/*Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i].
We need to write a function MatrixChainOrder() that should return the minimum number of multiplications needed to
 multiply the chain.
*/
#include<bits/stdc++.h>
using namespace std;

int wrapperMatrixChainOrder(int arr[], int start, int end)
{
    /*Base Case*/
    if (start >= end)
        return 0;

    int min_cost = INT_MAX;

    for (int k = start; k<end; k++)
    {
        int c1 = wrapperMatrixChainOrder(arr, start, k);
        int c2 = wrapperMatrixChainOrder(arr, k+1, end);
        int c3 = arr[start-1] * arr[k] * arr[end];

        min_cost = min(min_cost, (c1+c2+c3));
    }
    return min_cost;
}

int MatrixChainOrder(int arr[], int size)
{
    return wrapperMatrixChainOrder(arr, 1, size-1);
}

int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, size);
    return 0;
}
