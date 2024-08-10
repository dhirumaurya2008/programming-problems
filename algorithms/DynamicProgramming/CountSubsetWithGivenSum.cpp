/*
Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.
Input: arr[] = {1, 2, 3, 3}, X = 6
Output: 3
All the possible subsets are {1, 2, 3},
{1, 2, 3} and {3, 3}

Input: arr[] = {1, 1, 1, 1}, X = 1
Output: 4
*/
#include<iostream>
#include<cstring>
using namespace std;

int subsetSum(int arr[], int size, int sum)
{
    int mt[size+1][sum+1];

    memset(mt, 0, sizeof(mt));

    for (int j=0; j<sum+1; j++)
        mt[0][j] = 0;

    for (int i=0; i<size+1; i++)
        mt[i][0] = 1;

    for (int i=1; i<size+1; i++)
    {
        for (int j=1; j<sum+1; j++)
        {
            if (arr[i-1] <= j)
            {
                mt[i][j] = mt[i-1][j-arr[i-1]] + mt[i-1][j];
            }
            else
            {
                mt[i][j] = mt[i-1][j];
            }
        }
    }
    return mt[size][sum];
}

int main()
{
    int n = 4;
    int a[] = {3,3,3,3};
    int sum = 6;

    cout << "Number of subsets which having sum "<< sum << " is "<< (subsetSum(a, n, sum));
    return 0;
}
