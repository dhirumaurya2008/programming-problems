/*
Given a string of size ‘n’. The task is to remove or delete the minimum number of characters from the string
so that the resultant string is a palindrome. Note: The order of characters should be maintained.
Example-
Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string

Input : geeksforgeeks
Output : 8
*/
#if 0
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#endif

#include<bits/stdc++.h>
using namespace std;

int LPS(string X, string Y, int m , int n)
{
   int t[m+1][n+1];

   for(int j=0; j<m+1; j++)
   {
       t[0][j] = 0;
   }

   for(int i=0; i<n+1; i++)
   {
       t[i][0] = 0;
   }

   int max_len = 0;
   for (int i=1; i<m+1; i++)
   {
       for(int j=1; j<n+1; j++)
       {
           if (X[i-1] == Y[j-1]) {
            t[i][j] = 1 + t[i-1][j-1];
           }
           else
           {
               t[i][j] = max(t[i-1][j], t[i][j-1]);
           }

           max_len = max(max_len, t[i][j]);
       }
   }
   cout << "max_len " << max_len << endl;
   return max_len;
}

int minimumNumberOfDeletions(string str)
{
  /*Find the LPS*/
  string str2 = str;

  reverse(str2.begin(), str2.end());

  int lps_length = LPS(str, str2, str.length(), str2.length());

  /*Min Deletion is = len(str) - length(LPS)*/
  return (str.length() - lps_length);



}

int main()
{
    string str = "geeksforgeeks";
    cout << "Minimum number of deletions = "
         << minimumNumberOfDeletions(str);
    return 0;
}

