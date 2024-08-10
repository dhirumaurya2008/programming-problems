/*
LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them.
 A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
  For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
*/
#include<iostream>
#include<bits/stdc++.h>
#include<cstring>

using namespace std;
#define M 6
#define N 7
int t[M+1][N+1];

int lcs(char *X, char *Y, int m, int n)
{

/*Initialization*/
  for (int j=0; j<n+1; j++)
    t[0][j] = 0;
  for (int i=0; i<m+1; i++)
    t[i][0] = 0;

 for (int i=1; i<m+1; i++)
 {
     for (int j=1; j<n+1; j++)
     {
         if (X[i-1] == Y[j-1])
            t[i][j] = 1 + t[i-1][j-1];
         else
            t[i][j] = max(t[i-1][j], t[i][j-1]);
     }
 }
 return t[m][n];
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    //int t[m+1][n+1];
    memset(t, -1, sizeof(t));

    cout<<"Length of LCS from Top-Down "<< lcs( X, Y, m, n) << endl ;

     cout<<"Length of LCS from Top Down Table is "<< t[m][n] ;

    return 0;
}
