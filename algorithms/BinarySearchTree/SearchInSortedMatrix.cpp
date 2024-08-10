/*
Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it.
Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order.
The designed algorithm should have linear time complexity.
*/
#include<iostream>
using namespace std;
void search(int arr[4][4], int n, int key)
{

  int row = n-1;
  int col = n-1;

  int i = 0; int j = col;

  while ( (i >=0 && i<=row) && (j>=0 && j<=col))
  {
      if (key == arr[i][j])
        break;
      if (key < arr[i][j])
            j--;
      else
            i++;
  }

  if ((i >=0 && i<row) && (j>=0 && j<=row))
    cout << " Found key " << key << " i = " << i << " j = " << j << endl;
  else
    cout << "Key not found" << endl;

}

int main()
{
    int mat[4][4] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } };
    search(mat, 4, 29);

    return 0;
}
