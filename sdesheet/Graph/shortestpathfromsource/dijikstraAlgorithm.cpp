#include<bits/stdc++.h>
using namespace std;

void diskstra(vector<pair<int, int>> g[], int source, int V) {

    //priority_queue<pair<dist,node>> pq;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> distTo(V+1, INT_MAX);
    distTo[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first; //fetch distance
        int prev = pq.top().second; //fetch vertices

        pq.pop();

        /*Iterate to all the adjacent vertices */
        for (auto it : g[prev]) {
            int nextV = it.first; /*Fetch the next vertex*/
            int nextDist = it.second; /*Fetch the distance to new vertex from prev vertex*/

            /*If new distance to reach vertex nextV is lesser than update it*/
            if (distTo[nextV] > nextDist + distTo[prev]) {
                distTo[nextV] = nextDist + distTo[prev];
                pq.push({distTo[nextV], nextV});
            }
        }
    }
    cout << "The distances from source " << source << " are : \n";
	for(int i = 1 ; i<=V ; i++)	cout << distTo[i] << " ";
	cout << "\n";

}
int main()
{
    int n=5,m=6,source=1;

    /*pair<dstV, weight>*/
    vector<pair<int, int>> g[n+1];

    g[1].push_back({2,2});
    g[1].push_back({4,1});
    g[2].push_back({1,2});
    g[2].push_back({5,5});
    g[2].push_back({3,4});
    g[3].push_back({2,4});
    g[3].push_back({4,3});
    g[3].push_back({5,1});
    g[4].push_back({1,1});
    g[4].push_back({3,3});
    g[5].push_back({2,5});
    g[5].push_back({3,1});

    diskstra(g, source, 5);
    return 0;
}
