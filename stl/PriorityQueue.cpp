#include<iostream>
#include<queue>
using namespace std;

int main()
{

    /*Max Priority Queue*/
    priority_queue<int> q;

    q.push(50);
    q.push(700);
    q.push(30);
    q.push(20);
    q.push(790);
    q.push(510);

    cout << "Max Priority Queue = " << q.top() << endl ;
    q.pop();
     cout << "second Max Priority Queue = " << q.top() << endl ;

     /*Min Priority Queue*/
    priority_queue<int, vector<int>, greater<int>> minQ;
     minQ.push(50);
    minQ.push(700);
    minQ.push(30);
    minQ.push(20);
    minQ.push(790);
    minQ.push(510);
     cout << "Min Priority Queue = " << minQ.top() << endl ;
    minQ.pop();
     cout << "second Min Priority Queue = " << minQ.top() << endl ;
   return 0;
}
