/*https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &arr, int target)
{
    vector<vector<int>> res;

    sort(arr.begin(), arr.end());

    int low , high, newTarget;

    for (int i = 0; (i<arr.size()-2); i++)
    {
       if ((i==0) || ( i>0 && (arr[i] != arr[i-1])))
       {
               newTarget = target - arr[i];
               low = i+1;
               high = arr.size()-1;
               /*Now the problem reduced to 2 sum with newTarget*/
               while (low < high)
               {

                       if (arr[low] + arr[high] == newTarget)
                       {
                           vector <int> subRes(3);
                           subRes[0] = arr[i];
                           subRes[1] = arr[low];
                           subRes[2] = arr[high];
                           res.push_back(subRes);

                           while (low < high && arr[low] == arr[low+1])
                            low++;
                           while (low < high && arr[high] == arr[high-1])
                            high--;
                           low++;high--;
                       }
                       else if (arr[low] + arr[high] < newTarget)
                       {
                           low++;
                       }
                       else
                       {
                           high--;
                       }

                   }
       }
    }

    return res;

}

int main() {
  vector < int > arr{-1,0,1,2,-1,-4};
  vector < vector < int >> ans;
  ans = threeSum(arr, 0);
  cout << "The triplets are as follows: "<< endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] <<" ";
    }
    cout << endl;
  }
  return 0;
}
