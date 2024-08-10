
void printArr(int arr[], int arr_size, int B[])
{
    int sum =0;
    printf("\n");
    for(int i=0; i<arr_size; i++)
    {
        if(B[i]){
            printf("%d ", arr[i]);
        sum++;
    }
    }

    if(!sum)
    printf("Empty set");

}
void printAllSubset(int arr[], int arr_size, int k, int B[])
{
    if(k == (arr_size-1))
    {
      B[k] = 0;
      printArr(arr, arr_size, B);
      B[k] = 1;
      printArr(arr, arr_size, B);
    }
    else
    {
       B[k] = 0;
       printAllSubset(arr, arr_size, k+1, B);
       B[k] = 1;
       printAllSubset(arr, arr_size, k+1, B);
    }
}

int main()
{
    int arr[]={1,2,3};
    int arr_size=sizeof(arr)/sizeof(arr[0]);
    int B[3];
    for(int i=0; i<arr_size; i++)
    {
        B[i] =0;
    }
    printAllSubset(arr, arr_size, 0, B);

    return 0;
}
