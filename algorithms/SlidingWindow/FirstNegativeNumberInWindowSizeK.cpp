
#include<bits/stdc++.h>
using namespace std;

void printFirstNegativeInteger(int arr[], int k, int size)
{
    int i = 0;
    int j = 0;

    queue<int> q;
    while (j <size)
    {
        if (arr[j] < 0)
            q.push(arr[j]);
        /*Window not hit case*/
        if ((j-i+1) < k)
        {
            j++;
        }
        else if ((j-i+1) == k)
        {
            if (!q.empty())
                cout << q.front() << " ";
            else
                cout << 0 << " " ;
            if (arr[i] == q.front())
                q.pop();
            i++;j++;
        }
    }
}
// Driver code
int main()
{
     int arr[] = { 12, -1, -7, 8, -15, 30, 16, 28};
      int n = sizeof(arr)/sizeof(arr[0]);
     int k = 3;
     printFirstNegativeInteger(arr, k, n);
}
