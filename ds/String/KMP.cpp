#include<bits/stdc++.h>
using namespace std;

void buildPrefixTable(string &P, vector<int> &F)
{
    int i = 1, j=0;
    while (i<P.size())
    {
        /*Case matched P[i], P[j]*/
        if (P[i] == P[j])
        {
            F[i] = j+1;
            i++;
            j++;
        }
        else if (j>0)
        {/*now check in 0 to j-1 substring if there is match*/
            j = F[j-1];
        }
        else
        {/*0 char is matched*/
            F[i] = 0;
            i++;
        }
    }
}
int KMPSearch(string &P, string &T)
{
    vector<int> F(P.size());
    buildPrefixTable(P, F);
    int i = 0, j = 0;
    while (i<T.size())
    {
        if (P[j] == T[i])
        {
            if (j == (P.size()-1))
                return (i-j);
            else
            {
                i++;
                j++;
            }
        }
        else if (j>0)
        {
            j = F[j-1];
        }
        else
        {
            i++;
        }
    }
    return -1;
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pat= "ABABCABAB";
    cout << "Pattern found at index " << KMPSearch(pat, text);
    return 0;
}
