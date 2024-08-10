/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
how many ways can we make the change? The order of coins doesn’t matter.For example, for N = 4 and S = {1,2,3},
there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6},
there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/

#include<iostream>
#include<cstring>
using namespace std;
int countNumberOfWays(int arr[], int size, int bigNoteValue)
{
    int t[size+1][bigNoteValue+1];

    memset(t, 0, sizeof(t));

    for(int j=0; j<bigNoteValue+1; j++)
        t[0][j] = 0;
    for (int i=0; i<size+1; i++)
        t[i][0] = 1;

    for (int i=1; i<size+1; i++)
    {
        for (int j=1; j<bigNoteValue+1; j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j] = t[i-1][j] + t[i][ j - arr[i-1]];
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[size][bigNoteValue];
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    cout << countNumberOfWays(arr, m, n);
    return 0;
}
