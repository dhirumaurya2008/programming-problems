/*
Input: p[] = {40, 20, 30, 10, 30}
Output: 26000
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
Let the input 4 matrices be A, B, C and D.  The minimum number of
multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30
*/
#include<bits/stdc++.h>
using namespace std;
int t[4+1][4+1];

int wrapperMatrixChainOrder(int arr[], int i, int j)
{
    /*either single element remaining or no element*/
   if (i>=j)
    return 0;

   /*Value already computed in earlier subproblem. No need to calculate it this time*/
   if (t[i][j] != -1)
    return t[i][j];

    int mn = INT_MAX;

    for (int k = i; k<j; k++)
    {
        int c1 = wrapperMatrixChainOrder(arr, i, k);
        int c2 = wrapperMatrixChainOrder(arr, k+1, j);
        int c3 = arr[i-1] * arr[k] * arr[j];

        int tempAns = c1 + c2 + c3;

        mn = min(mn, tempAns);
    }
    t[i][j] = mn;
    return mn;
}

int MatrixChainOrder(int arr[], int size)
{
    return wrapperMatrixChainOrder(arr, 1, size-1);
}

int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    memset(t, -1, sizeof(t));

    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr,  n);
}
