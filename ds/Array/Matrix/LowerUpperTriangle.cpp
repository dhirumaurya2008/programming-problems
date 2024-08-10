#include<iostream>
using namespace std;
#define ROW 6
#define COL 6

void print_lower_trinagle(int matrix[ROW][COL])
{
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++) {
            if(j<=i)
                cout << matrix[i][j] << " ";
            else
                cout << " " << " ";
        }
        cout << endl;
    }
}

void print_upper_trinagle(int matrix[ROW][COL])
{
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
             if(j>=i)
                cout << matrix[i][j] << " ";
            else
                cout << " " << " ";
        }
        cout << endl;
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
      {48,45,34,31,10,6}
	};

	cout << "\n Lower triangle matrix " << endl ;
    print_lower_trinagle(matrix);
    cout << "\n Upper triangle matrix " << endl ;
    print_upper_trinagle(matrix);

	return 0;
}
