/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/

#include<iostream>
#include<cstring>
using namespace std;

/*
Objective - This function will take array, array size, and desired sum and will return number of ways the desired
sum user can get from different subsets of array items.
*/
int numOfSubsetsForGivenSum(int arr[], int size, int sum)
{
    //Two D array table for smaller inputs.
    int t[size+1][sum+1];

    memset(t, 0, sizeof(t));

    //Initialization
    for (int j = 0; j<sum+1; j++)
        t[0][j] = 0;
    for (int i = 0; i<size+1; i++)
        t[i][0] = 1;

    for (int i = 1; i<size+1; i++)
    {
        for (int j = 1; j<sum+1; j++)
        {
            if (arr[i-1] <= j)
            {
                t[i][j] = t[i-1][j] + t[i-1][j- arr[i-1]];
            }
            else
            {
                 t[i][j] = t[i-1][j];
            }
        }
    }

    return t[size][sum];
}

int getTargetSumWays(int arr[], int size, int targetSum)
{
    int range = 0;
    /*Calculate the range*/
    for (int i=0; i<size; i++)
        range += arr[i];
    //Find s1 and s2
    int s1 = (targetSum + range)/2;

    //Find min of s1 and s2
    s1 = min(s1, range-s1);

    return numOfSubsetsForGivenSum(arr, size, s1);

    //number of subsets for s1
}


int main()
{
    int a[] = {1,1,1,1,1};
    int n = sizeof(a)/sizeof(a[0]);
    int targetSum = 3;

    cout << "Number of getting the targetsum"<< targetSum << " is "<< (getTargetSumWays(a, n, targetSum));
    return 0;
}

