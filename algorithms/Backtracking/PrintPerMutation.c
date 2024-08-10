

void printAllPermutation(int arr[], int arr_size,int K)
{
   /*Base Case*/
   if(K == arr_size)
   {
       for(int i=0; i<arr_size; i++)
        printf("%d\t", arr[i]);
       printf("\n");
   }
   else
   {

      for(int i=K; i<arr_size; i++)
      {
          printf("K:i (%d:%d)\n", K, i);
          int temp = arr[K];
          arr[K] = arr[i];
          arr[i] = temp;
          printAllPermutation(arr, arr_size, K+1);
          temp = arr[K];
          arr[K] = arr[i];
          arr[i] = temp;
      }
   }
}
int main()
{
    int arr[]={1,2,3,4};
    int arr_size=sizeof(arr)/sizeof(arr[0]);
    int K = 0;
    printAllPermutation(arr, arr_size, K);

    return 0;
}
