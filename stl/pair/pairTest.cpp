#include<bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, string> p1, p2;
    /*1 way to initialize*/
    {
    p1.first = 10;
    p1.second = "dhiru";
    cout << p1.first << " " << p1.second <<endl;
    }

    /*2 way to initialize*/
     {
        p1 = {20, "Dhiru"};
        cout << p1.first << " " << p1.second <<endl;
     }

    /*3 way to initialize*/
     {
        p1 = make_pair(40, "Maurya");
        cout << p1.first << " " << p1.second <<endl;
     }

    /*4 way to initialize*/
     {
        p2 = p1;
        cout << p2.first << " " << p2.second <<endl;

     }

     /*5 way to initialize*/
     {
         p1 = make_pair(50, "Dhirendra Maurya");
        pair<int, string> &p3 = p1;
        cout << p3.first << " " << p3.second <<endl;
        p3.first = 60;
         cout << p1.first << " " << p1.second <<endl;

     }

     /*Array of paris*/
     pair<int, int> p[3];
     p[0] = {1,2};
     p[1] = {2,3};
     p[2] = {3, 4};

     for (int i=0; i<3; i++)
     {
         cout << p[i].first << " " << p[i].second <<endl;
     }

     swap(p[0], p[2]);

     for (int i=0; i<3; i++)
     {
         cout << p[i].first << " " << p[i].second <<endl;
     }

     pair<int, int> p5;
     cin >> p5.first;
     cin >>p5.second;
     cout << p5.first << " " << p5.second <<endl;

    return 0;
}
