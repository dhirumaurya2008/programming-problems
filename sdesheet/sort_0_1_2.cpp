void sort012(int *arr, int n)
{
   //   Write your code here
    int i = 0; /*index that point to unknown region start*/
    int j = 0; /*start index that point to region of 1's*/
    /*last index that point to reagion on unknown,
     k+1 to end points to region of2*/
    /*0 to j-1 will be region of 0's*/
    int k = n-1;
    while (i <=k)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[j]);
            i++;j++;
        }
        else if (arr[i] == 1)
        {
            i++;
        }
        else
        {
             swap(arr[i], arr[k]);
              k--;
        }
    }
}
