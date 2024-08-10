/*
Find position of an element in a sorted array of infinite numbers
*/
#include<iostream>
using namespace std;

int findPos(int arr[], int key)
{
    int start = 0, end = 1;
    int mid = -1;

   //cout << "sizeof(arr) " << sizeof(arr) << " sizeof(arr[0]) " << sizeof(arr[0]) << endl;
    //int size = sizeof(arr)/sizeof(arr[0]);

    while (key > arr[end])
    {
       //cout << "start " << start << " end " << end << " size "<< size << endl;
        if (end >=11)
            return -1;

        start = end;
        end = (end * 2);
    }

    cout << "start " << start << " end " << end << endl;
    while (start <= end)
    {
        mid = start + (end -start)/2;

        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
        {
            end = mid -1;
        }
        else
        {
            start = mid +1;
        }
    }
 return mid;

}

int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int ans = findPos(arr, 140);
    if (ans==-1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;
    return 0;
}
