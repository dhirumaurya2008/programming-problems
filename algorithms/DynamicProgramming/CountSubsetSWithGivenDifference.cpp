/*COunt the number of subsets with given difference*/
#include<iostream>
#include<cstring>
using namespace std;

int countSubSets(int arr[], int size, int sum)
{
    int t[size+1][sum+1];
    memset(t, 0, sizeof(t));

    for (int j=0; j<sum+1; j++)
        t[0][j] = 0;

    for (int i=0; i<size+1; i++)
        t[i][0] = 1;

    /*0/1 Knapsack Code*/

    for (int i=1; i<size+1; i++)
    {
        for (int j=1; j<sum+1; j++)
        {
            if (arr[i-1] <=j)
            {
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[size][sum];
}

int subsetsWithGivenDifference(int arr[], int size, int diff)
{
        int range = 0;

        for (int i = 0; i<size; i++)
            range += arr[i];

        int s1 = (range + diff)/2;

        s1 = min(s1, range-s1);

        return countSubSets(arr, size, s1);
}

int main()
{
   // int n = 4;
    int a[] = {1, 1,  2, 3};
    int n = sizeof(a)/sizeof(a[0]);
    int diff = 1;

    cout << "Number of subsets given difference "<< diff << " is "<< (subsetsWithGivenDifference(a, n, diff));
    return 0;
}
