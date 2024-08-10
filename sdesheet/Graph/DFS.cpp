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

int main() {
  vector < int > adj[5];

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 2, 4);

  vector < int > ans = dfsOfGraph(5, adj);
  printAns(ans);
  cout << endl;

  return 0;
}
