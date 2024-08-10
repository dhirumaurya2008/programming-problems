/*
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the
value of abs(sum(Subset1) – sum(Subset2)) should be minimum.
*/
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

vector<int> createSubsetSumForGivenRange(int arr[], int n, int range)
{
    /*Initialize the dp matrix*/
    bool t[n+1][range+1];
    for (int j=0; j<range+1; j++)
        t[0][j] = false;
    for (int i=0; i<n+1; i++)
        t[i][0] = true;

    for (int i=1; i<n+1; i++)
    {
        for (int j=1; j<range+1; j++)
        {
            if (arr[i-1] <= j)
            {
                t[i][j] = t[i-1][j-arr[i]] || t[i-1][j];
            }
            else
            {
                 t[i][j] = t[i-1][j];
            }
        }
    }

    vector<int> vec;
    /*filter the possible value subsets*/
    for (int j=0; j<=range/2; j++)
    {
        if (t[n][j])
            vec.push_back(j);
    }

    return vec;
}
int miniMumSubsetsDifference(int arr[], int n)
{
    int range  = 0;

    /*Step-1 find the range*/
    for (int i=0; i<n; i++)
        range += arr[i];

    vector<int> vec;
    /*Step-2 Compute the subset sum matrix for given range*/
    vec = createSubsetSumForGivenRange(arr, n, range);

    /*Step-3 Now put all the possible value in range/2 for t[N][i] into vector*/
    int minDiff = INT_MAX;
    cout << " range " << range << endl;
    for (int i=0; i<vec.size(); i++)
    {
        cout << "vect["<< i << " ] mindiff = " << minDiff << endl;
        minDiff = min(minDiff, abs(vec[i] - (range -vec[i])));
    }

    /*Step-4 Find the minimum of (Ri - (R-Ri)) for 0 to Range/2  */
    return minDiff;

}

int main()
{
    int arr[] = { 3, 1, 4, 2, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between 2 sets is "
         << miniMumSubsetsDifference(arr, n);
    return 0;
}
