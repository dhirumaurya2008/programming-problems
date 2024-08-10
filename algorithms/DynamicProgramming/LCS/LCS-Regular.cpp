/*
LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them.
 A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
  For example, �abc�, �abg�, �bdf�, �aeg�, ��acefg�, .. etc are subsequences of �abcdefg�.
LCS for input Sequences �ABCDGH� and �AEDFHR� is �ADH� of length 3.
LCS for input Sequences �AGGTAB� and �GXTXAYB� is �GTAB� of length 4.
*/
#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int lcs(char *X, char *Y, int m, int n)
{
  /*If one of string is of length 0 then return 0*/
  if ( (m==0) || (n == 0))
    return 0;

  /*If last char of both string is matched*/
  if (X[m-1] == Y[n-1])
  {
      return (1+lcs(X,Y, m-1, n-1));
  }
  else /*If last char of both string is not matched, the take max of reducing either of strings size 1*/
    return (max(lcs(X,Y, m-1, n), lcs(X,Y, m, n-1)));
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;

    return 0;
}
