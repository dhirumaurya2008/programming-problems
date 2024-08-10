#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int num1 = -1, num2 = -1;
    int count1=0, count2 = 0;
    for (int i=0;i<arr.size(); i++)
    {
        if (arr[i] == num1)
            count1++;
        else if (arr[i] == num2)
            count2++;
        else if (count1 == 0)
        {
            num1 = arr[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            num2 = arr[i];
            count2 = 1;
        }
        else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    for (int i=0;i<arr.size(); i++)
    {
        if (arr[i] == num1)
            count1++;
        else if (arr[i] == num2)
            count2++;
    }

    vector<int> res;
    if (count1 > (arr.size()/3))
        res.push_back(num1);
    if (count2 > (arr.size()/3))
        res.push_back(num2);
	return res;
}

int main()
{
    vector<int> vec = {3, 2, 2, 1, 5, 2, 3};
    vector<int> result = majorityElementII(vec);

    for (int i=0; i<result.size(); i++)
    {
        cout << "Result " << i << " = " << result[i] << " " ;
    }
    return 0;
}
