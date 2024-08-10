/*Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.
Input: arr[]   = {3, 0, 2, 0, 4}
Output: 7
int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxWater(int arr[], int n){

vector<int> leftGreatest(n, 0), rightGreatest(n, 0);

leftGreatest[0] = arr[0];

for(int i=1; i<n; i++)
{
   leftGreatest[i] = max(leftGreatest[i-1], arr[i]);
}


rightGreatest[n-1] = arr[n-1];
for(int i=n-2; i>=0; i--)
{
   rightGreatest[i] = max(rightGreatest[i+1], arr[i]);
}

//reverse(rightGreatest.begin(), rightGreatest.end());

 int trapWater = 0;

 for (int i=0; i<n; i++)
 {
     cout << "[ "<< i<< " | "<< rightGreatest[i] << " , " <<  leftGreatest[i] << " | min = " << min(rightGreatest[i], leftGreatest[i]);
     cout  << " , sumToIncreement = "<< min(rightGreatest[i], leftGreatest[i]) - arr[i] << " ] " << endl ;
    trapWater += ( min(rightGreatest[i], leftGreatest[i]) - arr[i]);
 }

  return trapWater;
}

int main() {
   // int arr[] = {3, 0, 2, 0, 4};
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int n = sizeof(arr)/sizeof(arr[0]);


    cout << "\n Input array is \n" << endl;
    for (int i=0; i<n; i++)
 {
     cout << arr[i] << " " ;
 }

 cout << endl;
    cout << maxWater(arr, n) << endl;
    return 0;
}
