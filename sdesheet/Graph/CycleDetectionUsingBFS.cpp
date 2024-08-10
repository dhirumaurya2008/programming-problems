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

bool isCycle(int src, vector<int> adj[], int v, vector<bool> &visited) {

    queue<pair<int, int>> q; //pair<src, parrent>
    visited[src] = true;
    q.push({src, -1});
    while (!q.empty()) {
        int node = q.front().first;
        int parrent = q.front().second;
        q.pop();
        for (auto val : adj[node]) {
            if (!visited[val]) {
                visited[val] = true;
                q.push({val, node});
            }
            else if (val != parrent) { // Node is already visited by someone
                return true;
            }
        }
    }
    return false;
}

bool checkForCycleUsingBFS(int v, vector<int> adj[]) {
    vector<bool> visited(v, false);

    for (int i = 0; i<v; i++) {
        if (!visited[i] && isCycle(i, adj, v, visited)) {
            cout << "Cycle found at " << i << endl;
            return true;
        }
    }
    return false;
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
#if 1
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

 // vector < int > ans = bfsOfGraph(5, adj);
  //printAns(ans);
 // cout << endl;
   checkForCycleUsingBFS(5, adj)?cout << "Graph contains cycle\n":cout << "Graph doesn't contain cycle\n";

  return 0;
}
