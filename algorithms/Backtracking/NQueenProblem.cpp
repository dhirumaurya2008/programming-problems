/* C/C++ program to solve N Queen Problem using
backtracking */

#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define v_v_char vector<vector<char>>

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
void printSolution(v_v_char &board)
{
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			printf(" %c ", board[i][j]);
			//msleep(400000);
			sleep(1);
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
bool isSafe(v_v_char &board, int row, int col)
{
    int dupRow = row;
    int dupCol = col;

   /*case 1: Check for upper left diagonal*/
   while (row>=0 && col >=0)
   {
       if (board[row][col] == 'Q')
        return false;
       row--;
       col--;
   }

   /*Case 2: check for left columns in same rows*/
   col = dupCol;
   row = dupRow;
   while (col>=0)
   {
     if (board[row][col] == 'Q')
        return false;
     col--;
   }

   /*case 3: check for left lower diagonal*/
   col = dupCol;
   row = dupRow;
   while (row<board.size() && col>=0)
   {
       if (board[row][col] == 'Q')
        return false;
       row++;
       col--;
   }

   return true;
}

/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(v_v_char &board, int col)
{
   if(col == board.size())
   {
       printSolution(board);
       gCount++;
       return true;
   }
   else
   {
       for(int i=0; i<board.size(); i++)
       {
           if(isSafe(board, i, col))
           {
             board[i][col] = 'Q';  //choose
             //if(solveNQUtil(board, col+1))
               // return true;
             solveNQUtil(board, col+1); //Explore
               // return true;

              board[i][col] = '-'; //Unchoose
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
	v_v_char board = { { '-','-', '-', '-' },
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
