/*
Given two sequences, print the longest subsequence present in both of them.
*/
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

void printLCS(char *X, char *Y, int m, int n)
{
   int t[m+1][n+1];

   for (int j=0; j<n+1; j++)
    t[0][j] = 0;
   for (int i=0; i<m+1; i++)
    t[i][0] = 0;

   for (int i=1; i<m+1; i++)
   {
       for(int j=1; j<n+1; j++)
       {
           if (X[i-1] == Y[j-1])
           {
               t[i][j] = 1 + t[i-1][j-1];
           }
           else
           {
               t[i][j] = max (t[i-1][j], t[i][j-1]);
           }
       }
   }

   int i = m;
   int j = n;
   string s = "";
   while(i>0 && j>0) {
    if (X[i-1] == Y[j-1]) {
        s.push_back(X[i-1]);
        i--, j--;
   }
   else if (t[i-1][j] > t[j-1][i] )
   {
       i--;
   }
   else
   {
       j--;
   }
}
   reverse(s.begin(), s.end());
 cout << " LCS of " << X << " and " << Y << " is " << s << endl;
}

/* Driver program to test above function */
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  int m = strlen(X);
  int n = strlen(Y);
  printLCS(X, Y, m, n);
  return 0;
}
