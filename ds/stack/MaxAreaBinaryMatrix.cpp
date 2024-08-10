/*Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.
Input:
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
Output :
8
*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

#define col 4

void NSL(vector<int> &vec, vector<int> &nearestSL)
{
  stack<pair<int, int>> st;
  for(int i=0; i<vec.size(); i++){
    if (st.empty()) {
        nearestSL.push_back(-1);
    }
    else if ((st.top().first < vec[i]))
    {
         nearestSL.push_back(st.top().second);
    }
    else if ((st.top().first >= vec[i]))
    {
        while (!st.empty() && (st.top().first >= vec[i]))
            st.pop();
        if(st.empty())
            nearestSL.push_back(-1);
        else
           nearestSL.push_back(st.top().second);
    }
    st.push({vec[i], i});
  }

  cout << "\n Next Smaller to left values array are -" << endl;
        for(int i=0; i<nearestSL.size(); i++)
        {
            cout << nearestSL[i] << " " ;
        }
}

void NSR(vector<int> &vec, vector<int> &nearestSR)
{
    stack<pair<int,int>> st;
    for (int i=vec.size()-1; i>=0; i--) {
        if(st.empty()){
            nearestSR.push_back(vec.size());
        }
        else if(st.top().first < vec[i]) {
            nearestSR.push_back(st.top().second);
        }
        else if (st.top().first >= vec[i]){
            while (!st.empty() && (st.top().first >= vec[i]))
                st.pop();
            if (st.empty())
                nearestSR.push_back(vec.size());
            else
              nearestSR.push_back(st.top().second);
        }
        st.push({vec[i], i});
    }
    reverse(nearestSR.begin(), nearestSR.end());
     cout << "\n Next Smaller to right values array are -" << endl;
        for(int i=0; i<nearestSR.size(); i++)
        {
            cout << nearestSR[i] << " " ;
        }
}

int getAreaRectangle(vector<int> &vec)
{
    vector<int> nearestSL, nearestSR, width(vec.size(), 0), area(vec.size(), 0);
    NSL(vec, nearestSL);
    NSR(vec, nearestSR);
    int maxArea = 0;
    cout << " \n Width "<< endl;
    for(int i=0; i<vec.size(); i++) {
      width[i] = (nearestSR[i] - nearestSL[i] -1);
      area[i] = (width[i] * vec[i]);
      cout << "[ " << width[i] << " , "  << area[i] << "], ";
      maxArea = max(area[i], maxArea);
    }
    cout << " \n MaxArea " << maxArea << endl;
    return maxArea;
}
int maxRectangle(int A[][col], int row)
{
    vector<int> vec(col, 0);
    int maxArea = 0;
    for(int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            vec[j] = A[i][j] ? (vec[j] + A[i][j]) : 0;
        }
        maxArea = max(getAreaRectangle(vec), maxArea);
    }

    return maxArea;
}

int main()
{
    int A[4][4] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };

    cout << "Area of maximum rectangle is "
         << maxRectangle(A, 4);

    return 0;
}
