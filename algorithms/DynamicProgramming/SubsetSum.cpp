/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set
with sum equal to given sum.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 5
#define S  19

static bool t[N+1][S+1];



bool subsetSum(int arr[])
{
    /*Initialize the array*/
    for (int j=0; j<S+1; j++)
        t[0][j] = false;

    for (int i=0; i<N+1; i++)
        t[i][0] = true;

    /*Fill the matrix*/
     for (int i=1; i<N+1; i++)
     {
         for (int j=1; j<S+1; j++)
         {
             /*choice diagram code*/
             if (arr[i-1] <= j)
             {
                 /*Max does not make sense hence taking ||*/
                 t[i][j] = ( t[i-1][j-arr[i-1]] || t[i-1][j]);
             }
             else
             {
                 t[i][j] = t[i-1][j];
             }
         }
     }
     return t[N][S];
}


    int main()
{
    // Storing the value -1 to the matrix
    memset(t, false, sizeof(t));
    int n = 5;
    int a[] = {1, 5, 3, 7, 4};
    //int sum = 12;

    if (subsetSum(a))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}
