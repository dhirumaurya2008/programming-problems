/*
Given a string you need to print longest possible substring that has exactly M unique characters.
If there are more than one substring of longest possible length, then print any one of them.
*/
#include<bits/stdc++.h>
using namespace std;

int lenLongestSubString(string s, int k)
{
    int start = 0, j = 0, maxSubStrLen = 0;
    map<char, int> mp;
    mp.clear();

    while (j < s.length())
    {
        if (mp.find(s[j]) != mp.end())
            mp[s[j]]++;
        else
            mp[s[j]] = 1;

        /*check the condition*/
        if (mp.size() < k)
            j++;
        else if (mp.size() == k)
        {
            int windowSize = j-start+1;
            maxSubStrLen = max(maxSubStrLen, windowSize);
            j++;
        }
        else if (mp.size() >k )
        {
            while (mp.size() >k)
            {
                mp[s[start]]--;
                if ( mp[s[start]] == 0)
                    mp.erase(s[start]);
                start++;
            }
            j++;
        }

    }
    return maxSubStrLen;
}

int main()
{
    string s = "aabacbebebe";
    int k = 3;
    cout << "Longest substring with k unique char" << lenLongestSubString(s, k);
    return 0;
}
