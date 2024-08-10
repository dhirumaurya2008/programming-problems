/*
Given a word and a text, return the count of the occurrences of anagrams of the word in the text
(For eg: anagrams of word for are for, ofr, rof etc.))
*/
#include<bits/stdc++.h>
using namespace std;

int countAnagrams(string text, string word)
{

    map<char, int> mp;
    int i = 0, counter = 0;
     /*create map for word*/
    while (i < word.length())
    {
        if (mp.find(word[i]) != mp.end())
            mp[word[i]]++;
        else
        {
            mp[word[i]] = 1;
            counter++;
        }

        i++;
    }
    cout << " counter " << counter << endl;
    int j = 0;
    i = 0;
    int k = word.length();
    cout << " k = " << k << endl;
    int ans = 0;
    while (j < text.length())
    {

        if ((mp.find(text[j]) != mp.end())){
             mp[text[j]]--;

            if (mp[text[j]] == 0)
                counter--;

        }
        printf("Window [%d %d] a,b (%d, %d)\n", i, j, mp['a'], mp['b']);
        //printf("%c counter : mp[word[f]] :  mp[word[o]] :  mp[word[r]] (%d : %d :%d : %d)\n", word[j], counter, mp[word[0]], mp[word[1]], mp[word[2]] );

        if (j-i+1 < k)
        {
            j++;
        }
        else if (j -i +1 == k)
        {
            if (counter == 0) {
                printf("Anagram found at index - %d \n", j);
                ans++;

            }
             /*Since index i is going out from window*/
                if (mp.find(text[i]) != mp.end()){
                        mp[text[i]]++;
                        if (mp[text[i]] == 1)
                          counter++;
                        printf("Exit Window [%d %d] a,b (%d, %d)\n", i, j, mp['a'], mp['b']);
                }
             i++;
             j++;

        }

    }
    return ans;
}
// Driver Code
int main()
{
    //string text = "forxxorfxdofr";
    //string word = "for";
    string text = "aaxbaabaa";
    string word = "aaba";
    cout << text << endl;
    cout << countAnagrams(text, word);

    return 0;
}

