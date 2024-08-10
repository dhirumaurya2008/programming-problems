#include<bits/stdc++.h>
using namespace std;

void DFS_V1(int u, vector<int> adj[], stack<int> &mystack, vector<bool> &visited) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v])
            DFS_V1(v, adj, mystack, visited);
    }
    /*Put in stack once all outgoing edges traversed*/
    mystack.push(u);
    cout << "Pusing " << u << " into the stack " << endl;
}

void DFS_V2(int u, vector<int> revAdj[], vector<bool> &visited) {
    cout << u << " " ;
    visited[u] = true;
    for (auto v : revAdj[u]) {
        if (!visited[v])
            DFS_V2(v, revAdj, visited);
    }
}


void transPoseGraph(vector<int> adj[], int V, vector<int> revAdj[]) {

    for (int i=1; i<V+1; i++) {
        for (int j : adj[i]) {
            revAdj[j].push_back(i);
        }
    }
}

void find_SCC(vector<int> adj[], int V)
{
    stack<int> mystack;
    vector<bool> visited(V+1, false);
    vector<int> revAdj[V+1];

    for (int i=1; i<V+1; i++) {

        if (!visited[i])
            DFS_V1(i, adj, mystack, visited);
    }

    transPoseGraph(adj, V, revAdj);

    for (int i=1; i<V+1; i++) {
        visited[i] = false;
    }

    cout << "Strongly Connected Component are " << endl;

    while (!mystack.empty()) {
        int cur = mystack.top();
        mystack.pop();
        if (!visited[cur]) {
            cout << "New component started " << endl;
            DFS_V2(cur, revAdj, visited);
            cout << "\n";
        }
    }

}

int main() {

    int V = 6;
    vector<int> adj[V+1];
    adj[1].push_back(3);
	adj[2].push_back(1);
	adj[3].push_back(2);
	adj[3].push_back(5);
	adj[4].push_back(6);
	adj[5].push_back(4);
	adj[6].push_back(5);

    find_SCC(adj, V);

    return 0;
}
