#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

typedef struct _EdgePair
{
    int m_src;
    int m_dst;
    int m_weight;
   // EdgePair() = default;
    // constructor
    _EdgePair(int src, int dst, int weight):m_src(src),m_dst(dst),m_weight(weight) {}
}EdgePair;


// overload the operator<
bool operator<(const EdgePair &x, const EdgePair &y) {
    if (x.m_weight < y.m_weight)
        return true;
    return false;
}

int main()
{
    vector<EdgePair> edgePair;

    edgePair.push_back({0,1, 5});
    edgePair.push_back({0,2, 34});
    edgePair.push_back({0,3, 20});
    edgePair.push_back({1,3, 30});
    edgePair.push_back({1,2, 12});
    edgePair.push_back({1,4, 8});
    edgePair.push_back({4,1, 10});
    edgePair.push_back({4,3, 50});

    for(auto x: edgePair){
        cout << "src = " << x.m_src << " dst = " << x.m_dst << " weight = " << x.m_weight << endl;
    }

    sort(edgePair.begin(), edgePair.end());

    cout << "\n After Sorting \n" << endl;
        for(auto x: edgePair){
        cout << "src = " << x.m_src << " dst = " << x.m_dst << " weight = " << x.m_weight << endl;
    }

return 0;
}
