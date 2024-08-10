#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int src, int dst) {
  adj[src].push_back(dst);
}

void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i<V; i++) {
        cout << "Edge List of vertex " << i << " is: " ;
        for (auto val: adj[i]) {
            cout << val << " ";
        }
        cout <<endl;
    }
}

bool checkCycle(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis) {

    vis[node] = true;
    dfsVis[node] = true;

    for (auto it : adj[node]) {
        cout << "SrcNode =  " << node << " dstNode= " << it << endl;
        if (vis[it] == false) {
            if (checkCycle(it, adj, vis, dfsVis)) {
                return true;
            }
        }
          else if (dfsVis[it] == true){ //Same node visited again in same direction
                return true;
            }
    }
    dfsVis[node] = false;
    return false;
}

bool isCyclic(vector<int> adj[], int N)
{
    vector<bool> vis(N,false);
    vector<bool> dfsVis(N, false);
    for (int i=0; i<N; i++) {
        if (vis[i] == false) {
            if (checkCycle(i, adj, vis, dfsVis)) {
                cout << "Dhiru - there is cycle " << endl;
                return true;
            }
            else {
                cout << "Dhiru - there is NO cycle " << endl;
            }
        }
    }
    return false;
}

int main()
{
    // Create a graph given in the above diagram
    vector<int> adj[4];

    addEdge(adj, 0, 1);
    addEdge(adj,0, 2);
    addEdge(adj,1, 2);
    addEdge(adj,2, 0);
    addEdge(adj,2, 3);
    addEdge(adj,3, 3);

    printGraph(adj, 4);

    if(isCyclic(adj, 4))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
