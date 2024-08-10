#include<stdio.h>

void rev_array(int arr[], int start , int end)
{
    int t=0;

   while(start < end)
   {
      t = arr[start];
      arr[start] = arr[end];
      arr[end] = t;
      start++;end--;
   }

}

void rev_array_compl(int arr[], int d , int n)
{

  rev_array(arr, 0, d-1);
  rev_array(arr, d, n-1);
  rev_array(arr, 0, n-1);
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

    rev_array_compl(arr, 2, 7);
    printf("Array after roation\n");
    print_array(arr, 7);
 return 0;
}
