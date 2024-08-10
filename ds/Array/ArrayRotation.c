#include<stdio.h>

int cal_gcd(int n , int d)
{
    if (d == 0)
        return n;

    else
        return cal_gcd(d, n % d);
}

int rotate_array(int arr[], int d , int n)
{
    int last =0, t, k, gcd=0, j;

    gcd = cal_gcd(n, d);
    for(int i=0; i<gcd ; i++)
    {
        t = arr[i];
        j = i;
        while(1)
        {
           k = (j + d)%7;

            if(k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = t;
    }

   return 0;
}

void print_array(int arr[], int n)
{
    for(int i=0; i<n; i++)
    printf("%d\t", arr[i]);
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    printf("Array before roation\n");
    print_array(arr, 7);

    rotate_array(arr, 3, 7);
    printf("Array after roation\n");
    print_array(arr, 7);
 return 0;
}
