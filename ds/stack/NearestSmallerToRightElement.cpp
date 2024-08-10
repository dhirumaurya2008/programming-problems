#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

void NSL(int arr[], int n){

    vector<int> vec;
    stack<int> st;

    for(int i=n-1; i>=0 ; i--) {
        /*Case-1 stack is empty*/
        if (st.empty()){
            vec.push_back(-1);
        }
        else if (st.top() < arr[i]) {
            /*Case-2 stack top is lesser*/
            vec.push_back(st.top());
        }
        else if (st.top() > arr[i])  { /*Case-2 stack top is greater*/

            while (!st.empty() && st.top() >= arr[i])
                st.pop();

            if (st.empty())
                vec.push_back(-1);
            else
                vec.push_back(st.top());
        }

         st.push(arr[i]);
        }

        //This reverse we are doing as we traversing from last
        reverse(vec.begin(), vec.end());

        /*Print the values*/
        cout << " Next Smaller to right values array are -" << endl;
        for(int i=0; i<n; i++)
        {
            cout << vec[i] << " " ;
        }

    }

/* Driver code */
int main()
{
  int arr[] = { 10, 5, 11, 6, 20, 12};
  cout << "Array before " << endl ;
  int n = sizeof(arr) / sizeof(arr[0]);
  for (int index = 0; index <n; index++)
  {
      cout << arr[index] << " " ;
  }

    NSL(arr, n);
    return 0;
}
