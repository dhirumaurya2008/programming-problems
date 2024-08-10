#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int src, int dst) {
    adj[src][dst] = 1;
    adj[dst][src] = 1;
}

void printGraph(int V, vector<vector<int>> &adj) {
    for (int i=0; i<V; i++) {
        cout << "Adjacency List of vertex " << i << " is : ";
        for (int j=0; j<V; j++) {
            if (adj[i][j])
                cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5; //number of vertices
    int m = 0; //number of edges
    vector<vector<int>> adj(n, vector<int>(n, 0));

    //for (int i=0;i<m;i++) {
        addEdge(adj, 0, 1);
        addEdge(adj, 0, 4);
        addEdge(adj, 1, 2);
        addEdge(adj, 1, 3);
        addEdge(adj, 1, 4);
        addEdge(adj, 2, 3);
        addEdge(adj, 3, 4);
   // }
    printGraph(n, adj);
    return 0;
}
