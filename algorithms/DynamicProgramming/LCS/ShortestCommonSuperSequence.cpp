/*
https://www.geeksforgeeks.org/shortest-common-supersequence/
Given two strings str1 and str2, the task is to find the length of the shortest string that has both str1 and str2 as subsequences.
Input:   str1 = "geek",  str2 = "eke"
Output: 5
Explanation:
String "geeke" has both string "geek"
and "eke" as subsequences.

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  9
Explanation:
String "AGXGTXAYB" has both string
"AGGTAB" and "GXTXAYB" as subsequences.
*/

#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int getShortestSuperSequenceLength(char *X, char *Y, int m, int n)
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

    return ( (m+n-common_max_length));

}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    cout << "Length of the shortest supersequence is "
         << getShortestSuperSequenceLength(X, Y, strlen(X), strlen(Y));
    return 0;
}
