#include<bits/stdc++.h>
using namespace std;
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    map<int, int> mp;
    int i = 0;
    int sum = 0;
    mp[sum] = -1;
    int cLen = 0;
    int maxLen = 0;

    while (i < (arr.size())) {
        sum += arr[i];
        map<int, int>::iterator it = mp.find(sum);
        if (it != mp.end()) {
            cLen = (i- it->second);
            maxLen = max(maxLen, cLen);
        }
        else
        {
            mp[sum] = i;
        }
    i++;
    }
	return maxLen;
}

int main()
{
  vector<int> arr = { 1, 3, -1, 4 ,-4 };

    cout << "Length of the longest 0 sum subarray is "
         << LongestSubsetWithZeroSum(arr);

    return 0;
}
