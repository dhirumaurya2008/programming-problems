#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int src, int dst){
 adj[src].push_back(dst);
 adj[dst].push_back(src);
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

int main()
{
    int V = 5;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}
