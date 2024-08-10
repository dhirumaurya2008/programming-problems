/*
Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1

Scrambled string:
Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.
Note: Scrambled string is not same as an Anagram
Below is one possible representation of str = “coder”:


    coder
   /    \
  co    der
 / \    /  \
c   o  d   er
           / \
          e   r
To scramble the string, we may choose any non-leaf node and swap its two children.
Suppose, we choose the node “co” and swap its two children, it produces a scrambled string “ocder”.


    ocder
   /    \
  oc    der
 / \    /  \
o   c  d   er
           / \
          e   r
Thus, “ocder” is a scrambled string of “coder”.
Similarly, if we continue to swap the children of nodes “der” and “er”, it produces a scrambled string “ocred”.


    ocred
   /    \
  oc    red
 / \    /  \
o   c  re  d
       / \
      r   e
Thus, “ocred” is a scrambled string of “coder”.
Examples:

Input: S1=”coder”, S2=”ocder”
Output: Yes
Explanation:
“ocder” is a scrambled form of “coder”
Input: S1=”abcde”, S2=”caebd”
Output: No
Explanation:
“caebd” is not a scrambled form of “abcde”

*/
#include<bits/stdc++.h>
using namespace std;

bool isScramble(string a, string b)
{
    if (a.compare(b) == 0)
        return true;

    if (a.length() == 1)
        return false;

    int n = a.length();
    bool flag = false;
    for (int k=1; k<n; k++)
    {
       /*Swapped case*/
       bool option1 = (isScramble(a.substr(0, k), b.substr(n-k, k)) &&
                        isScramble(a.substr(k, n-k), b.substr(0, n-k)));

       /*Non-swapped case*/
       bool option2 = (isScramble(a.substr(0, k), b.substr(0, k)) &&
                        isScramble(a.substr(k, n-k), b.substr(k, n-k)));

        if (option1 || option2)
        {
            flag  = true;
            break;
        }
    }
    return flag;
}

int main()
{
    string S1 = "coder";
    string S2 = "ocred";
    //S1="abcde", S2="caebd";

    if (isScramble(S1, S2)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}
