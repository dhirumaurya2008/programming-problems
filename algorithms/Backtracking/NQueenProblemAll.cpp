#include<bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector<vector<bool>> &visited) {
        /*Check in same row but left side*/
        for (int i = 0; i<=col; i++)
            if (visited[row][i])
                return false;

        /*check in left top diagonal*/
        int crow = row;
        int ccol = col;
        while (crow>=0 && ccol>=0)
        {
            if (visited[crow][ccol])
                return false;
            crow--;
            ccol--;
        }

        /*check in left botom diagonal*/
        crow = row;
        ccol = col;
        while (crow <visited.size() && ccol>=0)
        {
            if (visited[crow][ccol])
                return false;
            crow++;
            ccol--;
        }

        return true;
}

    void totalNQueensWrapper(int n, int col, vector<vector<bool>> &visited, int &solCount) {
        /*Base case*/
        if (col == n)
        {
            solCount++;
            return;
        }
        else {

            for (int row = 0; row<n; row++)
            {
                if (isValid(row, col, visited)) {
                    visited[row][col] = true;
                    totalNQueensWrapper(n, col+1,visited, solCount);
                    visited[row][col] = false;
                }
            }
        }
        return;
    }

    int totalNQueens(int n) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int solCount = 0;

        totalNQueensWrapper(n, 0, visited, solCount);

        return solCount;
    }

int main()
{
    cout << " Total solutions are " << totalNQueens(4) << endl;

}
