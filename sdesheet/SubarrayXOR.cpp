int subarraysXor(vector<int> &arr, int x)
{
  int ans = 0;
  for (int i=0; i<arr.size(); i++)
  {
      int xorVal = 0;
      for (int j=i; j<arr.size(); j++)
      {
          xorVal ^= arr[j];
          if (xorVal == x)
             ans++;
      }
  }
    return ans;
}
