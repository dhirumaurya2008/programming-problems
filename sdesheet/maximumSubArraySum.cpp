#include<climits>
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    int k = 1;
    int i = 0;
    int j = 0;
    long long sum = 0;
    long long ans = 0;
    while (k<=n)
    {
        int i = 0;
    	int j = 0;
        sum = 0;
        while (j<n)
        {
            sum += arr[j];
            if (j-i+1 < k)
                j++;
            else if (j-i+1 == k)
            {
                ans = max(ans, sum);
                sum -= arr[i];
                i++;j++;
            }
        }
        k++;
    }
    return ans;
}
