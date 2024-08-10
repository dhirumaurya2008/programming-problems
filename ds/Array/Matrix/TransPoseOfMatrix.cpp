/*
Transpose of a matrix is obtained by changing rows to columns and columns to rows. In other words, transpose of A[][] is obtained by changing A[i][j] to A[j][i].

matrix-transpose
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define N 4

void transposeInPlace(int C[][N])
{
   for(int i=0;i<N; i++)
    {
        for(int j=0; j<i; j++)
        {
            swap(C[i][j], C[j][i]);
        }
    }
}
void transpose(int A[][N], int B[][N])
{
    for(int i=0;i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            B[j][i] =  A[i][j];
        }
    }
}

int main()
{
    int A[N][N] = { {1, 1, 1, 7},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {9, 4, 4, 4}};

    int B[N][N], i, j;

    transpose(A, B);

    cout <<"Result matrix is \n";
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
           cout <<" "<< B[i][j];
        cout <<"\n";
    }

     int C[N][N] = { {1, 1, 1, 1},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {4, 4, 4, 4}};
    cout <<"\n Result matrix of C matrix transpose \n";
    transposeInPlace(C);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
           cout <<" "<< C[i][j];
        cout <<"\n";
    }

    return 0;
}
