#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bool flag = true;
    for (int i = 0; i<A.size(); i++)
    {
        if (A[i][0] == 0)
            flag = false;
        for (int j = 1; j<A[0].size(); j++)
        {
            if (A[i][j] == 0)
            {
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }

    for (int i=A.size()-1; i>=0;i--)
    {
        for (int j = A[0].size()-1; j>=1; j--)
        {
            if ((A[i][0] == 0) || (A[0][j] == 0))
                A[i][j] = 0;
            printf("%d ", A[i][j]);
        }

        if (flag == false) {
            A[i][0] = 0;
             printf("%d ", A[i][0]);
        }
        printf("\n");
    }
}

int main() {
  vector < vector < int >> arr;
  arr = {{0,0},{1,1} };
  setZeroes(arr);
  cout<<"The Final Matrix is "<<endl;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}
