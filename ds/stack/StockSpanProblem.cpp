
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}
*/
/*Crux of the problem is Find the index of nearest greater to left*/
void calculateSpan(vector<int> &price, int n, vector<int> &vec)
{
    stack<pair<int, int>> st;
    vector<int> vecTemp;

    for(int i=0; i<n; i++) {
        if (st.empty()) {
            vecTemp.push_back(-1);
        }
        else if (st.top().first >= price[i])
        {
            vecTemp.push_back(st.top().second);
        }
        else if (st.top().first < price[i])
        {
            while (!st.empty() && st.top().first < price[i])
                st.pop();
            if (st.empty())
                vecTemp.push_back(-1);
            else
                vecTemp.push_back(st.top().second);
        }
        st.push({price[i], i});
    }

    for (int i=0; i<n;i++)
    {
        vec[i] = (i-vecTemp[i]);
    }
    return;
}

void printArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    vector<int> price{ 100, 80, 60, 70, 60, 75, 85 };

    vector<int> vec(price.size(), 0);

    cout << "Input Array -" << endl;
    printArray(price, price.size());
    // Fill the span values in array S[]
    calculateSpan(price, price.size(), vec);

    cout << "\nFinal Array -" << endl;
    // print the calculated span values
    printArray(vec, price.size());

    return 0;
}
