/*
Given a 2D matrix, print all elements of the given matrix in diagonal order. For example, consider the following 5 X 4 input matrix.

*/
#include<iostream>
using namespace std;

#define R 5
#define C 4

void diagonalOrder(int A[R][C])
{
  /*Step-1 Print Row based diagonal*/
   for(int i=0; i<R; i++)
   {
       int row = i, col = 0;
       while((row >=0) && (col <C))
       {
           cout << A[row][col] << " " ;
           row--;col++;
       }
       cout << endl;
   }
  /*Step-2 Print Col based diagonal*/
    for(int i=1; i<C; i++)
   {
       int row = R-1, col = i;
       while((row >=0) && (col <C))
       {
           cout << A[row][col] << " " ;
           row--;col++;
       }
        cout << endl;
   }
}

int main()
{

    int arr[R][C] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 },
        { 17, 18, 19, 20 },
    };

    // Function call
    diagonalOrder(arr);
    return 0;
}
