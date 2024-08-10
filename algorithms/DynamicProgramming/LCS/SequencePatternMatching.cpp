/*Given two strings str1 and str2, find if str1 is a subsequence of str2.
A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order
of the remaining elements (source: wiki). Expected time complexity is linear.
*/
#include<bits/stdc++.h>
using namespace std;

bool isSubSequence(string X, string Y, int m, int n)
{
    int t[m+1][n+1];

    for (int j=0; j<n+1; j++)
    {
        t[0][j] = 0;
    }

    for (int i=0; i<m+1; i++)
        t[i][0] = 0;

    for (int i=1; i<m+1; i++)
    {
        for (int j=1; j<n+1; j++)
        {
            if (X[i-1] == Y[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }

    if (t[m][n] == m)
    {
     return true;
    }

    return false;

}

int main()
{
    char str1[] = "gksrek";
    char str2[] = "geeksforgeeks";
    int m = strlen(str1);
    int n = strlen(str2);
    isSubSequence(str1, str2, m, n) ? cout << "Yes "
                                    : cout << "No";
    return 0;
}
