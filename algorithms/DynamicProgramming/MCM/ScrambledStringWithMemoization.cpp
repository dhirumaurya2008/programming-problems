#include<bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;

bool isScramble(string a, string b)
{
    if (a.compare(b) == 0)
        return true;

    if (a.length() == 1)
        return false;
    /*make a key "a b"*/
    string key = a;
    key.push_back(' ');
    key.append(b);

    if (mp.find(key) != mp.end()) {
        cout << " For key = " << key << " value = " <<  mp[key] << " present in map" << endl;
        return mp[key];
    }

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
    mp[key] = flag;
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
