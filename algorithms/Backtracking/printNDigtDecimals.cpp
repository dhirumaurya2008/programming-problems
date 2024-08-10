/*Print all n digit binary number*/

#include<bits/stdc++.h>
using namespace std;

void printNDigitDecimalNumberHelper(int digitLeft, string soFar="")
{
    if (digitLeft == 0)
    {
        cout << soFar << endl;
    }
    else
    {
        for (char i=0; i<=9; i++)
        {
            printNDigitDecimalNumberHelper(digitLeft-1, soFar+to_string(i));
        }
    }
}

void printNDigitDecimalNumber(unsigned int n)
{
    printNDigitDecimalNumberHelper(n, "");
}

int main()
{
    printNDigitDecimalNumber(3);
    return 0;
}
