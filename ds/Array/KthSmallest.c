#include<stdio.h>
#include<limits.h>
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
#if 0
int kthSmallest(int arr[], int l, int u, int k)
{
    if(l<u){
    int index = partition(arr, l , u);

    if(k-1 == index-1)
        return arr[index-1];
    if(index-1 > k-1)
        return (kthSmallest(arr, l , index-1, k));
    else
       return (kthSmallest(arr,  index+1, u, k));
    }
    return INT_MAX;
}
#endif // 0
#if 0
int kthSmallest(int A[], int left, int right, int K)
{
    if (left == right)
         return A[left];
    int pos = partition(A, left, right);
    int count = pos - left + 1;
    if ( count == K )
         return A[pos];
    else if ( count > K )
         return kthSmallest(A, left, pos-1, K);
    else
         return kthSmallest(A, pos+1, right, K-i);
}
#endif // 0

int kthSmallest(int A[], int left, int right, int K)
{
    int pos=0;
    while(left<=right)
    {
       pos = partition(A, left, right);
       printf("pos %d", pos);
       if(K-1 == pos)
            return A[pos];
       else if(K < pos)
           right = pos-1;
       else
           left = pos+1;
    }
    return INT_MAX;
}


// Driver program to test above methods
int main()
{
	int arr[] = { 56, 3, 5, 7, 4, 19, 26 };
	//int arr[] = { 56};
	int n = sizeof(arr) / sizeof(arr[0]), k = 7;
	//cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k);
	printf("K'th smallest element is %d\n", kthSmallest(arr, 0, n - 1, k));
	return 0;
}
