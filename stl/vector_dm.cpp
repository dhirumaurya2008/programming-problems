#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &v)
{
    cout << endl <<"====================Print Start========================" << endl;
    cout <<"Vector Capecity : " << v.capacity() << endl;
    cout <<"Vector Size : " << v.size() << endl;
    cout <<"Vector Maxsize : " << v.max_size() << endl;
  for(auto val: v)
        cout << val << " ";
   cout << endl<<"====================Print end========================" << endl;
}

int main()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(5);
    v.push_back(3);
    v.push_back(20);
    v.push_back(22);
    //v.insert(v.begin()+3, 34);

    //Iterating vector from start to end
   #if 0
   vector<int>::iterator it1 = v.begin(), it2 = v.end();

   for(vector<int>::iterator it = it1; it != it2 ; it++)
    cout << (*it) << " ";

   #endif // 0

#if 1
   vector<int>::reverse_iterator it1 = v.rbegin(), it2 = v.rend();

   for(vector<int>::reverse_iterator it = it1; it != it2 ; it++)
   {
       *it = 45;
        cout << (*it) << " ";
   }


   #endif // 0

#if 0
   vector<int>::const_iterator it1 = v.cbegin(), it2 = v.cend();


   for(vector<int>::const_iterator it = it1; it != it2 ; it++)
   {
      //*it = 45;
      cout << (*it) << " ";
   }


   #endif // 0

   //printVector(v);
return 0;
}
