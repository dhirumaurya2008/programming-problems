#include<iostream>

using namespace std;


int maxContigousSubArray(int arr[], int arr_size)
{
    int g_max = arr[0], max_ending_here = arr[0];
    int start_index = 0, g_max_start_index =0;
    int end_index = 0, g_max_end_index = 0;
    for (int i = 1; i < arr_size; i++)
    {
        if (arr[i] > (arr[i] + max_ending_here))
        {
           max_ending_here = arr[i];
           start_index = i;
           end_index = i;
        }
        else
        {
           max_ending_here = (arr[i] + max_ending_here);
           end_index = i;
        }

        if (g_max < max_ending_here)
        {
            g_max_start_index = start_index;
            g_max_end_index = end_index;
            g_max = max_ending_here;
        }

    }
    int sum = 0;
    for (int i=g_max_start_index; i<=g_max_end_index; i++)
    {
        cout << " " << arr[i] << endl;
        sum = sum + arr[i];
    }
    cout << "Maximum contiguous sum is " << sum << endl;
    return g_max;
}

int main()
{

    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxContigousSubArray(a, n);
    //cout << "Maximum contiguous sum is " << max_sum << endl;
    return 0;
}
