#include<iostream>
using namespace std;
#define ROW 7
#define COL 6
void wave_view(int matrix[ROW][COL])
{
    for(int j= 0; j<COL; j++)
    {
        if (j%2 == 0) {
            for (int i = 0; i<ROW; i++)
                cout << matrix[i][j] << " ";
        }
        else
        {
            for (int i = ROW-1; i>=0; i--)
                cout << matrix[i][j] << " ";
        }
        cout << "  | " ;
    }

}

void reverse_wave_view(int matrix[ROW][COL])
{
    int dir = 0;
    for(int j= COL-1; j>=0; j--)
    {
        if (dir%2 == 0) {
            for (int i = 0; i<ROW; i++)
                cout << matrix[i][j] << " ";
        }
        else
        {
            for (int i = ROW-1; i>=0; i--)
                cout << matrix[i][j] << " ";
        }
        cout << "  | " ;
        dir++;
    }

}

int main()
{
	int matrix[ROW][COL] = {
      {60,40,39,16,15,1},
      {58,41,38,18,14,2},
      {55,42,37,19,13,3},
      {50,43,36,20,12,4},
      {49,44,35,21,11,5},
      {48,45,34,31,10,6},
      {47,46,33,32,9, 8}
	};
	wave_view(matrix);
    cout << "\n\n Reverse wave form " << endl;
	reverse_wave_view(matrix);
	return 0;
}
