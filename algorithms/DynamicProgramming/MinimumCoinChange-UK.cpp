/*
Given a value V, if we want to make a change for V cents, and we have an infinite supply of each of C = { C1, C2, .., Cm}
valued coins, what is the minimum number of coins to make the change? If it’s not possible to make a change, print -1.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int size, int V)
{
  int t[size+1][V+1];

  /*Initialization*/
  for(int i=0;i<size+1; i++)
  {
      for(int j=0; j<V+1; j++)
      {
          if (i == 0)
            t[i][j] = (INT_MAX -1);
          else
            t[i][j] = 0;
      }
  }
  //t[0][0] = 0;
  /*Special case initialize the second row*/
  for (int i=1;i<V+1; i++)
  {
     if (i % coins[0] == 0)
        t[1][i] = (i / coins[0]);
     else
        t[1][i] = (INT_MAX-1);
  }

  for (int i=2; i<size+1; i++)
  {
      for (int j=1; j<V+1; j++)
      {
          if (coins[i-1] <= j)
          {
              cout << " i = " << i << " j = " << j << " t[i][j- coins[i-1]] = " << t[i][j- coins[i-1]] << " t[i-1][j] = " << t[i-1][j]<< endl;
              t[i][j] = min((1+t[i][j- coins[i-1]]), t[i-1][j]) ;
          }
          else
          {
               cout << " i = " << i << " j = " << j << " t[i-1][j] = " << t[i-1][j]<< endl;
              t[i][j] = t[i-1][j];
          }
      }
  }
  cout << endl;
  for(int i=0; i<size+1;i++)
  {
      for (int j=0; j<V+1; j++)
      {
          cout << t[i][j] << "  |  ";
      }
      cout << endl;
  }
  return t[size][V];
}

int main()
{
    int coins[] =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    //int V = 11;
    int V = 12;
    cout << "Minimum coins required is "
         << minCoins(coins, m, V);
    return 0;
}
