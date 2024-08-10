/*
Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n.
Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if the length of the rod is 8
 and the values of different pieces are given as the following, then the maximum obtainable value is 22
 (by cutting in two pieces of lengths 2 and 6)
*/
#include<iostream>
#include<cstring>
using namespace std;

int maxValForRod(int price[], int length[], int size, int rodLen)
{
 int t[size+1][rodLen+1];
 memset(t, 0, sizeof(t));

 for (int j = 0; j<rodLen+1; j++)
    t[0][j] = 0;

 for (int i = 0; i<size+1; i++)
    t[i][0] = 0;

 for (int i = 1; i<size+1; i++)
 {
     for (int j = 1; j<rodLen+1; j++)
     {
         if (length[i-1] <= j)
         {
             t[i][j] = max ( ( t[i-1][j] ), (price[i-1] + t[i][j- length[i-1]]));
         }
         else
         {
             t[i][j] = t[i-1][j];
         }
     }

 }

 return t[size][rodLen];
}

int main()
{
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = sizeof(price) / sizeof(price[0]);
    int length[n];
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    int Max_len = n;

    // Function Call
    cout << "Maximum obtained value  is "
         << maxValForRod(price, length, n, Max_len) << endl;
}
