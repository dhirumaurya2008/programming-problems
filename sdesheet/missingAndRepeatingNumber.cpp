#include<bits/stdc++.h>
using namespace std;
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
    pair<int, int> res;
    int i = 0, j = 0;
    while (i<n)
    {

        j = arr[i]-1;

        if (arr[i] != i+1 && (arr[i] != arr[j]))
        {
           printf("case 1 arr[%d]=%d, arr[%d]=%d \n", i, arr[i], j, arr[j]);
           swap(arr[i], arr[j]);
        }
        else
        {
            printf("case 2 arr[%d]=%d, arr[%d]=%d \n", i, arr[i], j, arr[j]);
            i++;
        }

    }

    for (int i=0;i<n;i++)
    {
        if (arr[i] !=i+1)
        {
            res.first = i+1;
            res.second = arr[i];
            break;
        }
    }

    return res;
}

int main()
{

    vector<int> vec = {7, 5, 3, 2 ,1 ,6 ,6};
    pair<int, int> res = missingAndRepeating(vec, 7);
    cout << "Missing " << res.first << " duplicate " << res.second;
    return 0;
}
