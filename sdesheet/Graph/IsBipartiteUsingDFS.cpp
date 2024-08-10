#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int src, int dst){
 adj[src].push_back(dst);
 adj[dst].push_back(src);
}

bool checkIfBipartite(int node, vector<int> adj[], vector<int> &color) {

        for (auto it : adj[node]) {
            if (color[it] == -1) {
                color[it] = 1 - color[node];
                if (!checkIfBipartite(it, adj, color))
                    return false;
            }
            else if (color[it] == color[node])
                return false;
        }
        return true;
}

bool isBipartite(int V, vector<int> adj[]) {
   vector<int> color(V, -1);

   for (int i=0; i<V; i++) {
        if (color[i] == -1) {
            color[i] = 1;
            if (!checkIfBipartite(i, adj, color))
                return false;
        }
   }
   return true;
}

int main()
{

    int V;
    V = 5;
      //adjacency list for storing graph
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    #if 1
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 4);
    #endif


    bool ans = isBipartite(V, adj);
    //returns 1 if bipartite graph is possible
      if (ans)
        cout << "Yes\n";
    //returns 0 if bipartite graph is not possible
      else
        cout << "No\n";

    return 0;
}
