#include<bits/stdc++.h>
using namespace std;

//void printString(s)
int counter;
void perMuteStringHelper(string s, int k)
{

    if (k == s.length()-1)
    {
        cout << s << endl;
        counter++;
    }
    else
    {
        for (int i=k; i<s.length(); i++)
        {
            swap(s[k], s[i]);
            perMuteStringHelper(s, k+1);
            swap(s[k], s[i]);
        }
    }
}

void perMuteString(string s)
{
    int k =0;
    perMuteStringHelper(s, k);

}

int main()
{
    perMuteString("DHIRU");
    cout << "Total calls " << counter << endl;
    return 0;
}
