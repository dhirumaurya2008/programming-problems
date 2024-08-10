/*
Given string str, the task is to find the minimum number of characters to be inserted to convert it to a palindrome.
*/
#include<bits/stdc++.h>
using namespace std;

int findMinInsertionsLCS(string X, int m)
{
  string Y = X;
  reverse(Y.begin(), Y.end());
  int n = m;

  int t[m+1][n+1];

  for (int j=0; j<n+1; j++)
    t[0][j] = 0;
  for (int i=0; i<m+1; i++)
    t[i][0] = 0;
  /*Populate LCS table*/
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
              t[i][j] = max (t[i][j-1], t[i-1][j]);
          }
      }
  }

  return (m - t[m][n]);

}
// Driver code
int main()
{
    string str = "geeks";
    cout << "Min number of insertion to make X string palindrome is " << findMinInsertionsLCS(str, str.length());
    return 0;
}
