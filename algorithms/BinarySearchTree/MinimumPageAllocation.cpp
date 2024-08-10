/*
Given number of pages in n different books and m students.
The books are arranged in ascending order of number of pages.
 Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValidScheme(int arr[], int n, int m, int pages)
{
    int student = 1;
    int sum = 0;

    for (int i=0; i<n; i++)
    {
        sum += arr[i];

        if (sum > pages)
        {
            student++;
            sum = arr[i];
        }
        if (student >m)
            return false;
    }

    if (student == m)
        return true;
    return false;
}
int findPages(int arr[], int n, int m)
{
    int sum = 0;
    int max_in_arr = 0;

    /*Find the max and sum to decide the array range*/
    for (int i=0; i<n; i++)
    {
        sum += arr[i];
        max_in_arr = max(max_in_arr, arr[i]);
    }
    int start = max_in_arr;
    int end = sum ;
    int result = -1;
    while (start <= end)
    {
        int mid = start + (end -start)/2;

        if (isValidScheme(arr, n, m, mid) == true)
        {
            result = mid ;
            end = mid -1;
        }
        else
            start = mid +1;
    }

    return result;

}

int main()
{
    //Number of pages in books
    int arr[] = {12, 34, 67, 90};
    int n = sizeof arr / sizeof arr[0];
    int m = 2; //No. of students

    cout << "Minimum number of pages = "
         << findPages(arr, n, m) << endl;
    return 0;
}
