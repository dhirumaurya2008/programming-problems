/*
This problem is a variation of Matrix Chain Multiplication problem.
 If the string is a palindrome, then we simply return 0. Else,
 like the Matrix Chain Multiplication problem, we try making cuts at all possible places,
 recursively calculate the cost for each cut and return the minimum value.
Let the given string be str and minPalPartion() be the function that returns the fewest cuts needed for palindrome partitioning.
 following is the optimal substructure property.
*/
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
   while (i<=j)
   {
       if (s[i++] != s[j--])
        return false;
   }

   return true;
}

int minCutWrapper(string s, int i, int j, vector<vector<int>> &t)
{
    if (i>=j)
        return 0;

    if (isPalindrome(s, i, j))
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    int mn = INT_MAX;

    for (int k = i; k<=j-1; k++)
    {
        int tempAns = minCutWrapper(s, i, k, t) + 1 + minCutWrapper(s, k+1, j, t);
        mn = min(mn, tempAns);
    }
    return (t[i][j] = mn);

}

int minCut(string s)
{
    int length = s.length();
    vector<vector<int>> t( length+1 , vector<int> (length+1, -1));

    return (minCutWrapper(s, 0, length-1, t));
}

int main()
{
    cout << minCut("aab") << endl;
    cout << minCut("aabababaxx") << endl;
    return 0;
}
