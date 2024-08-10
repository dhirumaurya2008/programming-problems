#include<bits/stdc++.h>
using namespace std;

void printGraph(vector<pair<int, int>> adj[], int V)
{
    for (int i = 0; i<V; i++) {
        cout << "Edge List of vertex " << i << " is: " ;
        for (auto val: adj[i]) {
            cout << "{"<<val.first << " ," << val.second << "}" << " ";
        }
        cout <<endl;
    }
}

void addEdge(vector<pair<int, int>> adj[], int src, int dst, int weight)
{
    adj[src].push_back({dst, weight});
    adj[dst].push_back({src, weight});
}

#define P_I pair<int, int>
int mst(vector<pair<int, int>> adj[], int V) {

    vector<int> key(V, INT_MAX); //Key array help us in choosing the minimum weight edge which is not part of MST yet
    vector<bool> mst(V, false); //Contains all vertices which become part of MST
    vector<int> parrent(V, -1);   //parrent array help in finding the edges which is part of MST
    priority_queue<P_I, vector<P_I>, greater<P_I>> pq;

    key[0] = 0;
    parrent[0]= -1;

    pq.push({0, 0}); // {distance, u}

    while (!pq.empty()) {
        int u = pq.top().second;
        mst[u] = true;
        pq.pop();

        for (auto it: adj[u]) {
            int v = it.first;
            int wt = it.second;
            if ( (mst[v] == false) && (wt < key[v])) {
                key[v] =  wt;
                parrent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    int mstSum = 0;
    for (int i = 0; i<V; i++) {
        cout << " i = " << i << " key[i] " << key[i] << endl;
        mstSum += key[i];
    }
    return mstSum;
}

int main()
{
    int V = 5;
    /*pair<dst, weight>*/
    vector<pair<int, int>> adj[V];

    addEdge(adj,0, 1,2);
	addEdge(adj,0, 3,6);
	addEdge(adj,1,2,3);
	addEdge(adj,1,3,8);
	addEdge(adj,1,4,5);
	addEdge(adj,2,4,7);

	printGraph(adj, 5);
	cout << "MST of Graph using Prims algorithm is " << mst(adj, V);
	return 0;
}
