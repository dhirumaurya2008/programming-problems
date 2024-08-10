/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
For simplicity, assume that all bars have same width and the width is 1 unit.
*/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void NSL(int arr[], int n, vector<int> &vec)
{
    stack<pair<int, int>> st;

    for(int i=0; i<n ; i++) {
        /*Case-1 stack is empty*/
        if (st.empty()){
            vec.push_back(-1);
        }
        else if (st.top().first < arr[i]) {
            /*Case-2 stack top is lesser*/
            vec.push_back(st.top().second);
        }
        else if (st.top().first >= arr[i])  { /*Case-2 stack top is greater*/

            while (!st.empty() && st.top().first >= arr[i])
                st.pop();

            if (st.empty())
                vec.push_back(-1);
            else
                vec.push_back(st.top().second);
        }

        st.push({arr[i], i});
        }

        #if 1
        /*Print the values*/
        cout << "\n Next Smaller values array are -" << endl;
        for(int i=0; i<n; i++)
        {
            cout << vec[i] << " " ;
        }
        #endif

}

void NSR(int arr[], int n, vector<int> &vec)
{
    stack<pair<int, int>> st;

    for(int i=n-1; i>=0 ; i--) {
        /*Case-1 stack is empty*/
        if (st.empty()){
            vec.push_back(n);
        }
        else if (st.top().first < arr[i]) {
            /*Case-2 stack top is lesser*/
            vec.push_back(st.top().second);
        }
        else if (st.top().first >= arr[i])  { /*Case-2 stack top is greater*/

            while (!st.empty() && st.top().first >= arr[i])
                st.pop();

            if (st.empty())
                vec.push_back(n);
            else
                vec.push_back(st.top().second);
        }

         st.push({arr[i], i});
        }

        reverse(vec.begin(), vec.end());

        #if 1
        /*Print the values*/
        cout << "\n Next Smaller to right values array are -" << endl;
        for(int i=0; i<n; i++)
        {
            cout << vec[i] << " " ;
        }
        #endif


}

int getMaxArea(int arr[], int arr_size)
{
   vector<int>  nearestSL, nearestSR, width(arr_size, 0), area(arr_size, 0);

   NSL(arr, arr_size, nearestSL);
   NSR(arr, arr_size, nearestSR);
   int max_area = 0;
   cout << " \n Width "<< endl;
   for(int i=0; i<arr_size; i++) {
    width[i] = arr[i]?(nearestSR[i] - nearestSL[i] -1): 0;
    area[i] = ( width[i] * arr[i]);
    cout << "[ " << width[i] << " , "  << area[i] << "], ";
    max_area = max(max_area , area[i]);
   }
   return max_area;
}


int main()
 {
   int hist[] = {6, 2, 5, 4, 5, 1, 6};
   //int hist[] = {0, 1, 1, 0};
    int n = sizeof(hist)/sizeof(hist[0]);
      cout << "maxArea = " << getMaxArea(hist, n) << endl;
    return 0;
}
