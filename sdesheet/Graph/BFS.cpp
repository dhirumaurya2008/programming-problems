#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> visited(v, false);
    for (int i = 0; i<v; i++) {
        queue<int> q;
        if (!visited[i]) {
            visited[i] = true;
            q.push(i);
            ans.push_back(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto val : adj[node]) {
               if (!visited[val]) {
                    visited[val] = true;
                    q.push(val);
                    ans.push_back(val);
                }
            }
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

  vector < int > ans = bfsOfGraph(5, adj);
  printAns(ans);
  cout << endl;

  return 0;
}
