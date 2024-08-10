/*
Given a knapsack weight W and a set of n items with certain value vali and weight wti,
we need to calculate the maximum amount that could make up this quantity exactly.
 This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.
*/
#include<iostream>
#include<cstring>
using namespace std;

int unboundedKnapsack(int W, int size, int val[], int wt[])
{
    int t[size+1][W+1];
    memset(t, 0, sizeof(t));

    //Initialization
    for (int j = 0; j<W+1; j++)
        t[0][j] = 0;
    for (int i = 0; i<size+1; i++)
        t[i][0] = 0;

    //Choice diagram
    for (int i = 1; i<size+1; i++)
    {
        for (int j = 1; j<W+1; j++)
        {
            if (wt[i-1] <= j)
            {
                t[i][j] = max ( ( t[i-1][j] ) , ( val[i-1] + t[i][j - wt[i-1]] ));
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[size][W];
}

// Driver program
int main()
{
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val)/sizeof(val[0]);

    cout << "Maximum amount for unboundedKnapsack " << unboundedKnapsack(W, n, val, wt);

    return 0;
}
