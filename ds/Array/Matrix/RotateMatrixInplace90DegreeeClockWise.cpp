/*
Rotate a matrix by 90 degree in clockwise direction without using any extra space
Input:
1 2 3
4 5 6
7 8 9
Output:
7 4 1
8 5 2
9 6 3

Input:
1 2
3 4
Output:
3 1
4 2
*/

#include<iostream>
using namespace std;
#define N 4

void transpose(int A[][N])
{
    for(int i=0; i< N; i++)
    {
        for (int j=0; j<i; j++)
        {
            swap(A[i][j], A[j][i]);
        }
    }
}

void Reverse(int A[][N])
{
    for(int i=0; i<N; i++)
    {
        int start = 0, End = N-1;
        while(start < End)
        {
            swap(A[i][start], A[i][End]);
            start++;End--;
        }
    }
}

void Rotate(int A[][N])
{
    transpose(A);
    Reverse(A);
}

void print(int arr[N][N])
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
            cout << arr[i][j] << " ";

        cout << '\n';
    }
}

int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    cout << "Original matrix \n" << endl;
    print(arr);
    Rotate(arr);
     cout << "\n\n Resultant matrix \n" << endl;
    print(arr);

    return 0;
}
