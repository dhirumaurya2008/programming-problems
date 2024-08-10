#include<iostream>
#include<queue>
using namespace std;

struct minKeyComparator {
    bool operator()(pair<int , int> const& p1, pair<int, int> const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        if ((p1.first == p2.first) && (p1.second < p2.second))
        {
            return true;
        }
    }
};

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, minKeyComparator>
float arr[ROW][COL] = { { 30, 5.5 }, { 25, 5 },
                    { 20, 6 }, { 33, 6.1 }, { 23, 5.6 } };
}
