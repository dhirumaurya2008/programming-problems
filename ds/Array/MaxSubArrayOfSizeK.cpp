#include<iostream>

using namespace std;


int maxSumOfSubArrayOfSizeK(int arr[], int n, int k)
{
 int index = 0, max_sum = 0, sum = 0;
 while (index < k)
 {
   sum += arr[index++];
 }

 max_sum = sum;

 for (; index< n; index++)
 {
     sum = sum - arr[index -k] + arr[index];
     max_sum = max(sum, max_sum);
 }

 return max_sum;
}

int main()
{

    int a[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSumOfSubArrayOfSizeK(a, n, 4);
    cout << "maxSumOfSubArrayOfSize " << 4 << " = " << max_sum << endl;

    return 0;
}
