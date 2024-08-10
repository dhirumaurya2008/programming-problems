/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights
associated with n items respectively. Also given an integer W which represents knapsack capacity,
 find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
 You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
*/

#include<iostream>
#include<cstring>
using namespace std;
static int t[3+1][50+1];


int knapSackWithMemoization(int wt[], int val[], int W, int n)
{
    if ((n == 0) || (W == 0))
        return 0;
    if (wt[n-1] <= W)
    {
        return( t[n][W] = max ((val[n-1] + knapSackWithMemoization(wt, val, (W - wt[n-1]), n-1))/*Part of decision*/,
                        knapSackWithMemoization(wt, val, W, n-1) /*not part of decesion*/));
    }
    else
    {
        return (t[n][W] = knapSackWithMemoization(wt, val, W, n-1));
    }

    return 0;
}


int knapSack(int wt[], int val[], int W, int n)
{
    if ((n == 0) || (W == 0))
        return 0;
    if (wt[n-1] <= W)
    {
        return max ((val[n-1] + knapSack(wt, val, (W - wt[n-1]), n-1))/*Part of decision*/,
                        knapSack(wt, val, W, n-1) /*not part of decesion*/);
    }
    else
    {
        return knapSack(wt, val, W, n-1);
    }

    return -1;
}

int knapSackWithTopDown(int wt[], int val[], int W, int n)
{
    /*Intialization*/
    for (int i = 0; i<n; i++)
        t[i][0] = 0;
    for (int j = 0; j<W ; j++)
        t[0][j] = 0;

    for (int i=1; i<n+1; i++)
    {
        for (int j=1; j< W+1; j++)
        {
            /*Suitable*/
            if (wt[i-1] <= j)
            {
                t[i][j] = max ( (val[i-1] + t[i-1][j-wt[i-1]]), (t[i-1][j]));
            }
            else
            {
                t[i][j] =t[i-1][j];
            }
        }
    }

    return t[n][W];
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    //int W = 5;
    int n = sizeof(val) / sizeof(val[0]);
    memset(t, 0, sizeof(t));
    cout << "Recursive 0/1 knapsack max profit " <<  knapSack(wt, val, W, n) << endl;

    cout << "Recursive 0/1 knapsack with memoization max profit " << knapSackWithMemoization(wt, val, W, n) << endl;

    cout << "Recursive 0/1 knapsack with memoization max profit in tempArray " << t[3][50] << endl;
     memset(t, 0, sizeof(t));

     knapSackWithTopDown(wt, val, W, n);
     cout << "Top Down 0/1 knapsack  tempArray " << t[3][50] << endl;


    return 0;
}
