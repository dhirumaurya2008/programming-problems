/*
Given a sequence, find the length of the longest palindromic subsequence in it.
*/
#include<iostream>
#include<string>
#include<algorithm>
using  namespace std;

int lcs(string X, string Y, int m, int n)
{
   int t[m+1][n+1];

    /*Initialization block*/
    for (int j=0; j<n+1; j++)
        t[0][j] = 0;
    for (int i=0; i<m+1; i++)
        t[i][0] = 0;

    int common_max_length = 0;

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
                t[i][j] = max (t[i-1][j], t[i][j-1]);
            }
            common_max_length = max(common_max_length, t[i][j]);

        }

    }
    return common_max_length;
}

int lps(string s1)
{
   string s2 = s1;
   reverse(s2.begin(), s2.end());
   cout << " s1= " << s1 << " s2 = " << s2 << endl;

   return  lcs(s1, s2, s1.length(), s2.length());
}

int main()
{
    string s1 = "GEEKSFORGEEKS";

    cout << "The length of the LPS is "
         << lps(s1);
    return 0;
}
