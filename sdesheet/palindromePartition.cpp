#include<bits/stdc++.h>
#define VVS vector<vector<string>>
#define VS vector<string>
bool isPlaindrome(string s, int li, int hi)
{
    while (li<=hi) {
        if (s[li] != s[hi])
            return false;
        li++;
        hi--;
    }
    return true;
}
void partitionWrapper(string &s, VVS &result, VS &temp, int index) {
    if (index == s.size()) {
        result.push_back(temp);
        return;
    }
    else {

        for (int i=index; i<s.size(); i++) {
            if (isPlaindrome(s, index, i)) {
                temp.push_back(s.substr(index, i-index+1));
                partitionWrapper(s, result, temp, index+1);
                temp.pop_back();
            }
        }
    }
}
vector<vector<string>> partition(string &s)
{
    // Write your code here.
    VVS result;
    VS temp;
    int index = 0;
    partitionWrapper(s, result, temp, index);
    return result;
}
#undef VVS
#undef VS
