#include<bits/stdc++.h>
using namespace std;

void addEdge(int src, int dst, vector<int> adj[])
{
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

void topoSort(int node, vector<int> &vis, stack<int> &s, vector<int> adj[]) {
    vis[node] = 1;
    for (auto it: adj[node]) {
        if (vis[it] == 0) {
            topoSort(it, vis, s, adj);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(int V, vector<int> adj[])
{
    stack<int> s;
    vector<int> vis(V, 0);
    for(int i=0; i<V; i++) {
        if (vis[i] == 0) {
            topoSort(i, vis, s, adj);
        }
    }

    vector<int> res;
    while(!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

int main()
{
    // Create a graph given in the above diagram
    int V = 6;
    vector<int> adj[V];
    addEdge(5, 2, adj);
    addEdge(5, 0, adj);
    addEdge(4, 0, adj);
    addEdge(4, 1, adj);
    addEdge(2, 3, adj);
    addEdge(3, 1, adj);
    printGraph(adj, V);
    cout << "Following is a Topological Sort of the given "
            "graph \n";

    // Function Call
    vector<int> ans = topologicalSort(V, adj);

    for (auto it : ans) {
        cout << it << " " ;
    }

    return 0;
}
