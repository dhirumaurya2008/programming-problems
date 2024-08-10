#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
       // Write your code here.
    unordered_map<int, bool> mp;
    for(int i=0;i<n; i++)
    {
        mp[arr[i]] = true;
    }

    for (auto val : arr)
    {
        if (mp.find(val-1) != mp.end())
            mp[val] = false;
    }

    int maxTlen = 1;
    for (auto val: arr) {
        int tlen = 1;
        unordered_map<int, bool>::iterator it = mp.find(val);
        if (it->second == true)
        {
            cout << "case 3 " << val << endl;
            int tempVal = val+1;
            while (mp.find(tempVal) != mp.end()) {
                 cout << "case 4 " << val << endl;
                tlen++;
                tempVal++;
            }
            maxTlen = max(maxTlen, tlen);
        }
    }
    return maxTlen;
}

int main()
{
    vector<int> arr = {1, 6, 7, 8, 2, 3, 4, 9};
    cout << "Longest consequtive sequence " << lengthOfLongestConsecutiveSequence(arr, arr.size());
    return 0;
}
