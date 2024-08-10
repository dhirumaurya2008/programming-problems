//Count ways to obtain given sum by repeated throws of a dice
#include<iostream>
using namespace std;

int count ;
int diceRollSumHelper(unsigned int dice, unsigned int sum, int sumSoFar, int &nWays)
{
    count++;
    if (dice == 0) {
        if (sumSoFar == sum) {
            nWays = nWays + 1;
            //cout << endl;
            //cout << "nWays = " << nWays << endl;
        }
    }
    else {
        for (int i = 1; i<=6; i++)
        {
            if ( (sumSoFar + i + 1*(dice-1) <=sum ) && (sumSoFar + i + 6*(dice-1) >=sum ) )
            {
               // cout << " " << i ;
                diceRollSumHelper(dice-1, sum, sumSoFar+i, nWays);
            }
        }
    }
}

int diceRollSum(unsigned int dice, unsigned int sum)
{
    int sumSoFar = 0;
    int nWays = 0;
    diceRollSumHelper(dice, sum, sumSoFar, nWays);
    return nWays;
}

int main()
{
    unsigned int dice = 3;
    unsigned int sum = 12;
    int nWays = diceRollSum(dice, sum);
    cout << "nWays diceRollSum for dice = " << dice << " sum = " << sum << " | " <<   nWays << endl;
    cout << "Total number of calls " << count << endl;
    return 0;
}
