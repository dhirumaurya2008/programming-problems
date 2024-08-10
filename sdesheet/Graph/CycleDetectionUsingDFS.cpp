#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[],  vector<int> &ans, vector<bool> &visited) {

    visited[node] = true;
    ans.push_back(node);
    for (auto val : adj[node]) {
       if (!visited[val])
            DFS(val, adj, ans, visited);
    }
}

vector<int> dfsOfGraph(int v, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> visited(v, false);

    for (int i=0; i<v; i++)
    {
        if (!visited[i]) {
            DFS(i, adj, ans, visited);
        }
    }
    return ans;
}


void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void printAns(vector < int > & ans) {
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}

bool isCycle(int node, int parrent, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    for (auto val : adj[node]) {
        if (!visited[val]) {
            if (isCycle(val, node, adj, visited))
                return true;
        }
        else if (val != parrent) {
            return true;
        }
    }
    return false;
}

bool checkForCycleUsingDFS(int v, vector<int> adj[]){
    vector<bool> visited(v, false);
    for (int i = 0; i<v; i++) {
        if (!visited[i]) {
            if (isCycle(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main() {
  vector < int > adj[5];
#if 0
    addEdge(adj,1, 0);
    addEdge(adj,0, 2);
    addEdge(adj,2, 1);
    addEdge(adj,0, 3);
    addEdge(adj,3, 4);
#else
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 2, 4);
#endif
checkForCycleUsingDFS(5, adj)?cout << "Graph contains cycle\n":cout << "Graph doesn't contain cycle\n";

  #if 0
  vector < int > ans = dfsOfGraph(5, adj);
  printAns(ans);
  cout << endl;
  #endif
  return 0;
}
