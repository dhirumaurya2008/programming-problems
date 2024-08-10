void findSubsetsThatSumToKWrapper(vector<int> &arr, int n, int k, vector<int> &vec, vector<vector<int>> &result) {
   if (n == -1) {
       if (k == 0) {
           vector<int> temp(vec);
           result.push_back(temp);
       }
       return;
   }
   else {

       if (arr[n]<=k) {
       vec.push_back(arr[n]);
       findSubsetsThatSumToKWrapper(arr, n-1, k-arr[n], vec, result);
       vec.pop_back();
       }
       findSubsetsThatSumToKWrapper(arr, n-1, k, vec, result);
   }
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int> vec;
    vector<vector<int>> result;
    findSubsetsThatSumToKWrapper(arr, n-1, k, vec, result);

    return result;
    // Write your code here.
}
