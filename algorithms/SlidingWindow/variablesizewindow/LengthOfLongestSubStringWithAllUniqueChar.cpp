/*
Given a string str, find the length of the longest substring without repeating characters.

For “ABDEFGABEF”, the longest substring are “BDEFGA” and “DEFGAB”, with length 6.
For “BBBB” the longest substring is “B”, with length 1.
For “GEEKSFORGEEKS”, there are two longest substrings shown in the below diagrams, with length 7
*/

#include<bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string s)
{
    map<char, int> mp;
    int i = 0, j = 0, maxLen = 0;
    int windowSize = 0;

    while (j < s.length())
    {
        if (mp.find(s[j]) != mp.end())
            mp[s[j]]++;
        else
            mp[s[j]] = 1;

        /*condition hit */
        windowSize = (j-i+1);
        //printf("(i,j) = (%d, %d)\n", i, j);
        if (mp.size() == windowSize)
        {
            maxLen = max(maxLen, windowSize);
             printf("case1 (i,j) = (%d, %d)\n", i, j);
            j++;
        }
        else if(mp.size() < windowSize)
        {
            printf("case2 (i,j) = (%d, %d)\n", i, j);
            while (mp.size() < windowSize)
            {
                printf("    case3 (i,j) = (%d, %d)\n", i, j);
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
                windowSize = (j-i+1);
            }
            j++;
        }
    }

    return maxLen;

}

// Driver code
int main()
{
    string s = "geeksforgeeks";
    cout << "The input String is " << s << endl;
    int length = longestUniqueSubsttr(s);

    cout<<"The length of the longest non-repeating character "
        <<"substring is "
        << length;
}
