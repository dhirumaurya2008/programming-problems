vector<vector<long long int>> printPascal(int n)
{
  // Write your code here.
    vector<vector<long long int>> vec(n);
    for (int i = 1; i<=n; i++)
    {
        //vec[i-1].resize(i);
       for (int j=0;j<i; j++)
       {
           if ((j == 0) || (j == i-1))
           {
               vec[i-1].push_back(1);
           }
           else
           {
               vec[i-1].push_back(vec[i-2][j-1] + vec[i-2][j]);
           }
       }
    }
    return vec;
}
