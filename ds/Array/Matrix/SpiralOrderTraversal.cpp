/*
Input:

[  1   2   3   4  5 ]
[ 16  17  18  19  6 ]
[ 15  24  25  20  7 ]
[ 14  23  22  21  8 ]
[ 13  12  11  10  9 ]

Output:

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
*/
#include<iostream>
#include<vector>
using namespace std;

void printSpiralOrder( vector<vector<int>> const &mat)
{
  /*check for the size*/
  if (mat.size() <= 0)
    return;
  int top = 0, bottom = mat.size()-1, left = 0, right = mat.size()-1;
  int dir = 0; /*dir =0(left->right), dir =1(top->bottom), dir =2(right->left), dir =3(bottom->top)*/

  while(1)
  {
     if (left > right)
        break;
     if (dir == 0) {
        for (int i=left; i<=right; i++)
            cout << mat[top][i] << " " ;
        top++;
     }
    if (top > bottom)
        break;
     if (dir == 1){
        for (int i=top; i<=bottom; i++)
            cout << mat[i][right] << " " ;
        right--;
     }

   if (left > right)
        break;
     if (dir == 2)
     {
        for (int i=right; i>=left; i--)
            cout << mat[bottom][i] << " " ;
        bottom--;
     }
        if (top > bottom)
        break;
    if (dir == 3)
     {
          for (int i=bottom; i>=top; i--)
            cout << mat[i][left] << " " ;
        left++;
     }
     dir = (dir+1)%4;
  }
}

vector<int> spiralOrder(const vector<vector<int> > &A) {
    cout << "spiralOrder " << endl;
    int dir = 0, j = 0;
    int top = 0, bottom = A.size()-1;
    int left = 0, right = A[0].size()-1;
    vector<int> res( (A.size()* A[0].size()), 0);

    while (1) {
        /*left to right*/
        if (left > right)
        break;
        if (dir % 4 == 0)
        {
            for (int i = left; i<=right; i++) {
                cout << A[top][i] << " " ;
                res[j++] = A[top][i];
            }
            top++;
        }
        if (top > bottom)
        break;
        if (dir % 4 == 1)
        {
            for (int i = top; i<=bottom; i++) {
                    cout << A[i][right] << " " ;
                res[j++] = A[i][right];
            }
            right--;
        }
        if (left > right)
        break;
        if (dir % 4 == 2)
        {
            for (int i =right; i>=left; i--) {
                  cout << A[bottom][i] << " " ;
               res[j++] = A[bottom][i];
            }
            bottom--;
        }
        if (top > bottom)
        break;
         if (dir % 4 == 3)
        {
           for (int i =bottom; i>=top; i--) {
                cout << A[i][left] << " " ;
               res[j++] = A[i][left];
           }
            left++;
        }
        dir++;
    }
   return res;
}

int main()
{
    #if 0
    vector<vector<int>> mat =
    {
        { 1, 2, 3, 4, 5},
        {16, 17, 18, 19, 6},
        {15, 24, 25, 20, 7},
        {14, 23, 22, 21, 8},
        {13, 12, 11, 10, 9}
    };
    #endif // 0

    vector<vector<int>> mat =
    {
    { 1, 2, 3 },
    {4, 5, 6 },
    {7, 8, 9 }
    };

    printSpiralOrder(mat);

    vector<int> res = spiralOrder(mat);

    cout << " Returned result " << endl;
    for (auto x : res)
        cout << x << " " ;


    return 0;
}
