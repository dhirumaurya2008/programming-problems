#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void printNGE(int arr[], int n){
  if (n == 0)
    return ;
  stack<int> s;
  vector<int> v;
///11, 13, 21, 3
  for (int index = n-1; index >= 0 ; index--)
  {
      if (s.empty()) {
        v.push_back(-1);
      }
      else if ((s.size() > 0) && (s.top() > arr[index])) {
        v.push_back(s.top());
      }
      else if ((s.size() > 0) && (s.top() <= arr[index])) {

            while ((s.size() > 0) && (s.top() <= arr[index])){
                s.pop();
            }

            if (s.empty())
                v.push_back(-1);
            else {
                v.push_back(s.top());
            }
      }

      s.push(arr[index]);
  }

  cout << "\n Array after v.size() = " << v.size() << endl ;
  for (int index = v.size()-1; index >=0; index--)
  {
      cout << v[index] << " " ;
  }

  while ((s.size() > 0)){
            s.pop();
   }

}

/* Driver code */
int main()
{
  int arr[] = { 11, 13, 21, 3 };
  cout << "Array before " << endl ;



    int n = sizeof(arr) / sizeof(arr[0]);
      for (int index = 0; index <n; index++)
  {
      cout << arr[index] << " " ;
  }

    printNGE(arr, n);
    return 0;
}
