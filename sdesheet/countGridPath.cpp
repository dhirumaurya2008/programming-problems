#include<bits/stdc++.h>
using namespace std;

int uniquePathsWrapper(int i, int j, int m, int n) {
    // Write your code here.
    int count = 0;
     if ((i == m-1) && (j==n-1))
            return 1;
    if ((i == m) || (j==n))
    {
        return 0;
    }
    else
    {

        count += uniquePathsWrapper(i+1, j, m, n);
        count += uniquePathsWrapper(i, j+1, m, n);
    }
    return count;
}

int uniquePaths(int m, int n) {
	// Write your code here.
    int i = 0, j = 0;
    return (uniquePathsWrapper(i, j, m, n));
}

int main()
{
    cout << " Count " << uniquePaths(2, 2);
    return 0;
}
