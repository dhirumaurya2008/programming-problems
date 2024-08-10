#include<iostream>

using namespace std;

int maxContigousSubArraySum(int arr[], int arr_size)
{
    int g_max = arr[0], max_ending_here = arr[0];
    for (int i = 1; i < arr_size; i++)
    {
        max_ending_here = max(arr[i], (arr[i] + max_ending_here));
        g_max = max(g_max, max_ending_here);
    }
    return g_max;
}

int main()
{

    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxContigousSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    return 0;
}
