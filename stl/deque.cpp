#include<iostream>
#include<deque>
using namespace std;
int main()
{

    deque<int> deq;

    deq.push_back(4);
    deq.push_back(5);
    deq.push_back(6);
    deq.push_front(7);

    deque<int>::iterator it1 = deq.begin() ;

    for(deque<int>::iterator it = it1; it !=deq.end();  it++)
        cout << *it<<" ";

    cout << endl <<"Size will be " << deq.size() << endl;
    cout << "max_size will be " << deq.max_size() << endl;

    cout << "Empty " << deq.empty() << endl;

    cout << "pop_back " << endl;
    deq.pop_back();
     for(deque<int>::iterator it = it1; it !=deq.end();  it++)
        cout << *it<<" ";

    cout << endl <<  "pop_front " << endl;
    deq.pop_front();
     for(auto val:deq)
        cout << val<<" ";

    deq.push_back(5);
    deq.push_back(6);
    cout << endl <<  "pop_front " << endl;
     for(auto val:deq)
        cout << val<<" ";

 it1 = deq.begin() ;
    deq.erase(it1);
     cout << endl <<  "erase " << endl;
for(auto val:deq)
        cout << val<<" ";
cout << endl <<"at " << deq.at(2) << endl;
        cout << endl <<  "clear " << endl;
            deq.clear();


     for(auto val:deq)
        cout << val<<" ";

cout << endl <<"Empty " << deq.empty() << endl;

    return 0;
}
