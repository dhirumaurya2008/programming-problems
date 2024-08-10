#include<iostream>
#include<vector>

/*In N*N matrix each cell had K rupees available. You can pick only one cell in each row.
And also there is fee associated in case you are changing column in next row that is
abs(previous row selected coulmn - current row choosen coulmn).
So you need to find maximize the sum can be collected.
*/

using namespace std;

int findMaxHelper(vector<vector<int>> &Arr, int row, int col, int curMax, int &maxSoFar)
{

   if(row == Arr.size())
   {
       if((maxSoFar < curMax)){
       cout << "Before maxSoFar" << maxSoFar << endl;
       maxSoFar = curMax;
       cout << "After maxSoFar" << maxSoFar << endl;

       }
   }
   else
   {
       cout << "Curr Row Started " << row<< endl;
       for(int i=0; i<Arr[row].size(); i++)
       {
          cout << "Curr Row:Curr col " << row  << ": " << i << "==>" << Arr[row][i] << endl;
          int cost =  abs(i-col);
          curMax = (curMax + Arr[row][i] )-cost;
          cout << "curMax" << curMax<< endl;
          findMaxHelper(Arr, row+1, i, curMax, maxSoFar);
          curMax = (curMax - Arr[row][i]) + cost;
       }
       cout << "Curr Row Ended " << row<< endl;
   }

}

int findMax( vector<vector<int>> &Arr)
{
    int curMax = 0, maxSoFar=0;
    cout << "Max column are " << Arr[0].size() << endl;

    for(int i=0; i<Arr[0].size(); i++)
    {
        findMaxHelper(Arr, 0, i, curMax, maxSoFar);
    }
    return maxSoFar;
}

int main()
{
    //vector<vector<int>> Arr(3, vector<int>(3,0));
     vector<vector<int>> Arr{
                                 { 4, 1, 20},
                                 { 2, 60, 12},
                                 { 5, 7, 8}
                             };

    cout << "Max collected coins are " << findMax(Arr) << endl;
    return 0;
}
