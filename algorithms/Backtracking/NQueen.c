/* C/C++ program to solve N Queen Problem using
backtracking */
#define N 4
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>

int gCount ;

int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

/* A utility function to print solution */
void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf(" %c ", board[i][j]);
			msleep(400000);
		}
		printf("\n");
	}
	printf("Printing done \n\n");
}

/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(int board[N][N], int row, int col)
{
   /*Check of all the column in current row*/
   for(int i=0; i<col; i++)
   {
       if(board[row][i] == 'Q')
        return false;
   }

   /*Check for top left diagonal*/
   for(int i=row, j=col; i>=0 && j>=0; i--, j--)
   {
       if(board[i][j] == 'Q')
        return false;
   }

   /*Check for bottom left diagonal*/
   for(int i=row, j=col; i<N && j>=0; i++, j--)
   {
       if(board[i][j] == 'Q')
        return false;
   }

   return true;
}

/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(int board[N][N], int col)
{
   if(col == N)
   {
       printSolution(board);
       gCount++;
       return true;
   }
   else
   {
       for(int i=0; i<N; i++)
       {
           if(isSafe(board, i, col))
           {
             board[i][col] = 'Q';
             //if(solveNQUtil(board, col+1))
               // return true;
             solveNQUtil(board, col+1);
               // return true;

              board[i][col] = '-';
           }
       }
   }
   return false;
}

/* This function solves the N Queen problem using
Backtracking. It mainly uses solveNQUtil() to
solve the problem. It returns false if queens
cannot be placed, otherwise, return true and
prints placement of queens in the form of 1s.
Please note that there may be more than one
solutions, this function prints one of the
feasible solutions.*/
bool solveNQ()
{
	int board[N][N] = { { '-','-', '-', '-' },
						{ '-','-', '-', '-' },
						{ '-','-', '-', '-'},
						{ '-','-', '-', '-'} };

	if (solveNQUtil(board, 0) == false) {
		printf("Solution does not exist");
		return false;
	}

	//printSolution(board);
	return true;
}

// driver program to test above function
int main()
{
	solveNQ();
	printf("\n \n Total permutations are %d \n\n", gCount);
	return 0;
}
