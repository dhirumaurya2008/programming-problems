/*Given an unweighted graph, a source, and a destination, we need to find the shortest path from source to destination in
the graph in the most optimal way.
**/
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int src, int dst) {
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

int printShortestDistance(vector<int> adj[], int source, int dest, int v) {

    queue<int> q;
    vector<int> dst(v, INT_MAX);
    dst[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : adj[node]) {
            if ((dst[node] +1) < dst[it]) {
                dst[it] = dst[node] +1;
                q.push(it);
            }
        }
    }

    return dst[dest];
}

int main()
{
    // no. of vertices
    int v = 8;

    // array of vectors is used to store the graph
    // in the form of an adjacency list
    vector<int> adj[v];

    // Creating graph given in the above diagram.
    // addEdge function takes adjacency list, source
    // and destination vertex as argument and forms
    // an edge between them.
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 7);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 4, 7);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 7);
    printGraph(adj, v);

    int source = 0, dest = 7;
    int shortDist = printShortestDistance(adj, source, dest, v);
    cout << "Shortest Distance is " << shortDist << endl;
    return 0;
}
