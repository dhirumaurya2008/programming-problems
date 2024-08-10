#include<bits/stdc++.h>
using namespace std;

struct people
{
    int age,salary;

};
/*This comparator function will put lower values first and if 2 element have same value in first then compare
second whose value is lesser will come first.*/

struct compare
{
    bool operator()(const people & a, const people & b)
    {
        if(a.salary==b.salary)
        {
            return a.age>b.age;
        }
        else
        {
            return a.salary>b.salary;
        }

    }
};
int main()
{

    priority_queue<people,vector<people>,compare> pq;
    people person1,person2,person3;
    person1.salary=100;
    person1.age = 50;
    person2.salary=80;
    person2.age = 40;
    person3.salary = 100;
    person3.age=40;


    pq.push(person1);
    pq.push(person2);
    pq.push(person3);

    while(!pq.empty())
    {
        people p = pq.top();
        pq.pop();
        cout<<p.salary<<" "<<p.age<<endl;
    }
    return 0;
}
