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


int mst(vector<pair<int, int>> adj[], int V) {

    vector<int> key(V, INT_MAX); //Key array help us in choosing the minimum weight edge which is not part of MST yet
    vector<bool> mstTree(V, false); //Contains all vertices which become part of MST
    vector<int> parrent(V, -1);   //parrent array help in finding the edges which is part of MST

    key[0] = 0;
    parrent[0]= -1;

    int u;
    //This is because MST will contains at most V-1 edges
    for (int count = 0; count<V-1; count++) {
         int mini = INT_MAX;
         /*Now find the minimum edge weight for connecting vertex i to MST*/
        for (int i=0; i<V; i++) {
            if ((mstTree[i] == false) && (key[i] < mini)) {
                mini = key[i];
                u = i;
            }
        }

        /*Make u vertex as part of MST*/
        mstTree[u] = true;

        /*Now, update edges to all vertices which is not par of MST, for newly added vertex to MST*/
        for (auto it: adj[u]) {
            int v = it.first;
            int weight = it.second;
            /*mst*/
            if (mstTree[v] == false && ( weight < key[v]) ) {
                parrent[v] = u;
                key[v] = weight;
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
