/*The Longest Repeating Subsequence (LRS) problem is finding the longest subsequences of a string that occurs at least twice.
*/
#include<bits/stdc++.h>
using namespace std;

int LRSLength(string X, int m, int n)
{
    string Y = X;

    int t[m+1][n+1];
    for (int j=0; j<n+1; j++)
        t[0][j] = 0;
    for (int i=0; i<m+1; i++)
        t[i][0] = 0;

    int length = 0;
    for (int i=1; i<m+1; i++)
    {
        for (int j=1; j<n+1; j++)
        {
            if (X[i-1] == Y[j-1] && (i != j))
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

   return t[m][n];
}
int main()
{
    string X = "ATACTCGGA";
    int m = X.length();

    cout << "The length of the longest repeating subsequence is " <<
            LRSLength(X, m, m);

    return 0;
}
