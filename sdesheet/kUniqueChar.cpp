#include<bits/stdc++.h>
using namespace std;
int uniqueSubstrings(string input)
{
    //Write your code here
    unordered_map<char, int> mp;
    int windowLen = 0, maxWindowLen = 0;
    int j = 0, i = 0;
    while (j<input.length()) {
        if (mp.find(input[j]) != mp.end()) {
            printf("In map %c | (i, j) = (%d, %d)\n", input[j], i, j);
            mp[input[j]]++;
        }
        else {
             printf("Not in map %c | (i, j) = (%d, %d)\n", input[j], i, j);
            mp[input[j]] = 1;
        }
        windowLen = j-i+1;
        if (mp.size() == windowLen) {
            printf("map size same as window size | maxWindowLen = %d, windowLen=%d (i, j) = (%d, %d)\n", maxWindowLen, windowLen, i, j);
            maxWindowLen = max(maxWindowLen, windowLen);
            //cout << "maxWindowLen=" << maxWindowLen << " windowLen=" << windowLen << endl;
            j++;
        }
        else if (mp.size() < windowLen) {
            while ((mp.size() > 0) && (mp.size() <= windowLen)) {
                //printf("map size not as window size | maxWindowLen = %d, windowLen=%d (i, j) = (%d, %d)\n", maxWindowLen, windowLen, i, j);
                mp[input[i]]--;
                if (mp[input[i]] == 0) {
                    mp.erase(input[i]);
                }
                i++;
            }
            j++;
        }
    }
    return maxWindowLen;
}

int main()
{
    string s = "ababcdede";
    cout << " Uniqe Substring " << uniqueSubstrings(s) << endl;
    return 0;
}
