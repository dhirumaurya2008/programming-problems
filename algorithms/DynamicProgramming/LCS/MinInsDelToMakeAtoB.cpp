/*
Given two strings ‘str1’ and ‘str2’ of size m and n respectively.
The task is to remove/delete and insert the minimum number of characters from/in str1 to transform it into str2.
It could be possible that the same character needs to be removed/deleted from one point of str1 and
inserted to some another point.
https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/
Example
Input :
str1 = "heap", str2 = "pea"
Output :
Minimum Deletion = 2 and
Minimum Insertion = 1
Explanation:
p and h deleted from heap
Then, p is inserted at the beginning
One thing to note, though p was required yet
it was removed/deleted first from its position and
then it is inserted to some other position.
Thus, p contributes one to the deletion_count
and one to the insertion_count.
*/
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int LCS(string X, string Y, int m, int n)
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
void printMinDelAndInsert(string str1, string str2)
{
    int lcs_length = LCS(str1, str2, str1.length(), str2.length());

    cout << "Number of deletion " << ( str1.length() - lcs_length) << endl;
    cout << "Number of insertion " << ( str2.length() - lcs_length) << endl;
}

// Driver Code
int main()
{
    string str1 = "heap";
    string str2 = "pea";

      // Function Call
    printMinDelAndInsert(str1, str2);
    return 0;
}
