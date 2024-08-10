/*
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
nput : X = “GeeksforGeeks”, y = “GeeksQuiz”
Output : 5
Explanation:
The longest common substring is “Geeks” and is of length 5.

Input : X = “abcdxyz”, y = “xyzabcd”
Output : 4
Explanation:
The longest common substring is “abcd” and is of length 4.
*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int LCSubStr(string X, string Y, int m, int n)
{
    int t[m+1][n+1];
    memset(t, -1, sizeof(t));
    int max_length = 0;

    cout << "X = " << X << " X's length " << m << endl;
    cout << "Y = " << Y << " Y's length " << n << endl;

    for (int j=0; j<n+1; j++)
        t[0][j] = 0;
    for (int i=0; i<m+1; i++)
        t[i][0] = 0;

    for (int i=1; i<m+1; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            if (X[i-1] == Y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = 0;
            }
            max_length = max (max_length, t[i][j]);
        }
    }
    return max_length;
}

int main()
{
    string X = "OldSite:GeeksforGeeks.org";
    string Y = "NewSite:GeeksQuiz.com";

    int m = X.length();
    int n = Y.length();

    cout << "Longest common substring length is " << LCSubStr(X, Y, m, n);
    return 0;

}
