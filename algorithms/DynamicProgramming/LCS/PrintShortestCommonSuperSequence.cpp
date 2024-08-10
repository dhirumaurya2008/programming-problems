/*
Given two strings X and Y, print the shortest string that has both X and Y as subsequences.
If multiple shortest supersequence exists, print any one of them.
Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB"
OR Any string that represents shortest
supersequence of X and Y

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest
supersequence of X and Y
*/
#include<bits/stdc++.h>
using namespace std;

string printShortestSuperSeq(string X, string Y)
{
    /*Populate LCS table*/
    int m = X.length();
    int n = Y.length();

    int t[m+1][n+1];

    for (int j=0; j<n+1; j++)
        t[0][j] = 0;
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
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    /*ShortestSuperSeqLen = len(X)+len(Y)-len(LCS)*/
    /*Print with the help of table*/
    int i=m, j=n;
    string res = "";
    while (i>0 && j>0)
    {
        if (X[i-1] == Y[j-1])
        {
            res.push_back(X[i-1]);
            i--, j--;
        }
        else if (t[i-1][j] > t[i][j-1])
        {
            res.push_back(X[i-1]);
            i--;
        }
        else
        {
            res.push_back(Y[j-1]);
            j--;
        }
    }

    while (i>0)
    {
       res.push_back(X[i-1]);
       i--;
    }

    while (j>0)
    {
      res.push_back(Y[j-1]);
      j--;
    }

    reverse(res.begin(), res.end());

    cout << "Shortest common supersequence is " << res << endl;

    return res;
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    cout << printShortestSuperSeq(X, Y);

    return 0;
}
