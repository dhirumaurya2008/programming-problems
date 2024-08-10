/*
/*
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
Let the input be in form of two arrays one contains the symbols (T and F) in order and the other contains operators (&, | and ^}
 Input: symbol[]    = {T, F, T}
       operator[]  = {^, &}
Output: 2
The given expression is "T ^ F & T", it evaluates true
in two ways "((T ^ F) & T)" and "(T ^ (F & T))"

Input: symbol[]    = {T, F, F}
       operator[]  = {^, |}
Output: 2
The given expression is "T ^ F | F", it evaluates true
in two ways "( (T ^ F) | F )" and "( T ^ (F | F) )".
*/
#include<bits/stdc++.h>
using namespace std;

int parenthesis_count(string s, int i, int j, bool isTrue)
{
    /*Validate for empty string*/
    if (i > j)
        return false;
    /*string of length 1*/
    if (i == j)
    {
         if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    int ans = 0;
    for (int k = i +1; k<=j-1; k = k+2)
    {
        int lT = parenthesis_count(s, i, k-1, true);
        int lF =  parenthesis_count(s, i, k-1, false);
        int rT = parenthesis_count(s,  k+1, j , true);
        int rF =  parenthesis_count(s, k+1, j, false);

        if (s[k] == '&')
        {
            if (isTrue == true)
                ans = ans + (lT * rT);
            else
                ans = ans + (lT * rF) + (lF * rT) + (lF * rF);
        }
        else if (s[k] == '|')
        {
            if (isTrue == true)
                ans = ans + (lT * rT) + (lT * rF) + (lF * rT);
            else
                ans = ans + (lF * rF);
        }
        else if (s[k] == '^')
        {
            if (isTrue == true)
                ans = ans + (lT * rF) + (lF * rT);
            else
                ans = ans + (lT * rT) + (lF * rF);
        }

    }

    return ans;

}
int main()
{
    string symbols = "TTFT";
    string operators = "|&^";
    string s;
    int j = 0;

    /*Create complete string with symbol and operator*/
    for (int i=0; i<symbols.length(); i++)
    {
            s.push_back(symbols[i]);
            if ( j < operators.length())
                s.push_back(operators[j++]);
    }

    cout << "\n complete string " << s << endl;

    /*Now, we have complete string, apply the algortithm*/
    int number_of_ways = parenthesis_count(s, 0, s.length()-1, true);

    cout << " Number of putting parenthesis is " << number_of_ways << endl;
    return 0;
}
