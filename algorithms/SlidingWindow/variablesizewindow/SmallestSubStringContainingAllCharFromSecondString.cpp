/*Given two strings, string1 and string2, the task is to find the smallest substring in string1 containing all characters of
 string2 efficiently.
*/

#include<bits/stdc++.h>
using namespace std;

int SmallestSubString(string s, string t)
{
    map<char, int> mp;
    int i = 0, j = 0, counter = 0, minLen = INT_MAX;

    /*creation of map*/
    while (i < t.length())
    {
        if (mp.find(t[i]) != mp.end())
            mp[t[i]]++;
        else
        {
             mp[t[i]] = 1;
             counter++;
        }
        i++;
    }

    i = 0;

    while (j <s.length())
    {
        if (mp.find(s[j]) != mp.end())
        {
            //printf("case 0 (i, j, counter, m[s[j]]) (%d, %d, %d | %d)\n", i, j, counter, mp[s[j]]);
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                counter--;
        }
       // printf("case 1 (i, j) (%d, %d)\n", i, j);
        /*If cur char is not part of target string we do not care*/

       if (counter > 0)
       {
           //printf("case 1 (i, j, counter) (%d, %d, %d)\n", i, j, counter);
           j++;
       }
       else if ((counter == 0))
       {
          // printf("case 2 (i, j, counter) (%d, %d, %d)\n", i, j, counter);
           while ( (counter == 0))
           {
               //printf(" case 3 (i, j, counter) (%d, %d, %d)\n", i, j, counter);
               if (mp.find(s[i]) != mp.end())
               {
                   mp[s[i]]++;
                   if (mp[s[i]] == 1)
                    counter++;
               }
               minLen = min(minLen, j-i+1);
               i++;
           }
           j++;
       }
    }
    return minLen;
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

      cout<<"-->Smallest window that contain all character : "<<endl;
    cout << SmallestSubString(s, t);
}
