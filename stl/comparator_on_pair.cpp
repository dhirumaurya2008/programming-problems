#include<bits/stdc++.h>
using namespace std;


/*This comparator function will put lower values first and if 2 element have same value in first then compare
second whose value is lesser will come first.*/
struct comp {
    bool operator()(pair<int, int>a, pair<int, int>b)
    {
        if (a.first != b.first)
            return (a.first > b.first);

        return (a.second > a.second);
    }
};

int main()
{

    priority_queue<pair<int,int>,vector<pair<int,int>>, comp > pq;
    pair<int, int >  person1,person2,person3;
    person1.first=100;
    person1.second = 50;
    person2.first=80;
    person2.second = 40;
    person3.first = 100;
    person3.second=40;


    pq.push(person1);
    pq.push(person2);
    pq.push(person3);

    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}
