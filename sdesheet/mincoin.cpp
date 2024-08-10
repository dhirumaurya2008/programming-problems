#include<bits/stdc++.h>
using namespace std;
int findMinimumCoins(int amount)
{
    cout << "ammount " << amount << endl;
    // Write your code here
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    //int currAmmount = 0;
    int coinCount = 0;
    for (int i=coins.size()-1; i>=0; i--) {
        if (amount == 0)
            break;
        if (amount >= coins[i]) {
            int cnt = amount/coins[i];
            printf("amount %d, coins %d , cnt %d\n", amount, coins[i], cnt);
            if (cnt > 1) {
                coinCount += cnt;
                amount = amount - (cnt * coins[i]);
            }
            else {
                coinCount += 1;
                amount = amount - coins[i];
            }
            //currAmmount += ((cnt * coins[i]) + (amount - coins[i]);
            //amount = amount - ( (cnt * coins[i]) + coins[i]);
        }
        else
        {
            cout << "Greate value than amount  " << amount  << "coins " <<  coins[i]<< endl;
    // Write your code here

        }
    }
    return coinCount;
}


int main() {


cout << " findMinimumCoins = " << findMinimumCoins(13) ;
return 0;
}
