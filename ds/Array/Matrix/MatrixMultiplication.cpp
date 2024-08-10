/*Given two matrices, the task to multiply them. Matrices can either be square or rectangular.
  int mat1[N][N] = { { 1, 1, 1, 1 },
                       { 2, 2, 2, 2 },
                       { 3, 3, 3, 3 },
                       { 4, 4, 4, 4 } };

    int mat2[N][N] = { { 1, 1, 1, 1 },
                       { 2, 2, 2, 2 },
                       { 3, 3, 3, 3 },
                       { 4, 4, 4, 4 } };

Result matrix is
10 10 10 10
20 20 20 20
30 30 30 30
40 40 40 40
*/

#include<iostream>
using namespace std;
#define N 4
void  multiply(int mat1[][N], int mat2[][N], int res[][N])
{
    int sum = 0;
    for(int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            for (int k=0; k<N ; k++)
            {
                sum += mat1[i][k] * mat2[k][j];
            }
            res[i][j] = sum;
            sum = 0;
        }
    }

}
int main()
{
    int i, j;
    int res[N][N]; // To store result
    int mat1[N][N] = { { 1, 1, 1, 1 },
                       { 2, 2, 2, 2 },
                       { 3, 3, 3, 3 },
                       { 4, 4, 4, 4 } };

    int mat2[N][N] = { { 1, 1, 1, 1 },
                       { 2, 2, 2, 2 },
                       { 3, 3, 3, 3 },
                       { 4, 4, 4, 4 } };

    multiply(mat1, mat2, res);

    cout << "Result matrix is \n";
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
