#include<bits/stdc++.h>
using namespace std;


void DFS(int u, vector<int> adj[], vector<int> &low, vector<int> &disc, vector<bool> &presentInStack, stack<int> &mystack) {

    static int time = 0;
    low[u] = disc[u] = time;
    time = time +1;
    mystack.push(u);
    presentInStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
              DFS(v, adj, low, disc, presentInStack, mystack);
              low[u] = min(low[u], low[v]);
        }
        else if (presentInStack[v]) { /*Back Edge*/
            low[u] = min(low[u], disc[v]);
        }
    }


    if (low[u] == disc[u]) {
        cout << "New SCC component is : " ;
        while (mystack.top() != u) {
            cout << mystack.top() << " " ;
            presentInStack[mystack.top()] = false;
            mystack.pop();
        }
        cout << mystack.top() << " " ;
        presentInStack[mystack.top()] = false;
        mystack.pop();
        cout << endl;
    }
}


void find_SCC(vector<int> adj[], int V) {
    vector<int> low(V+1, -1), disc(V+1, -1);
    vector<bool> presentInStack(V+1, false);
    stack<int> mystack;

    for (int i=1; i<V+1; i++) {

        if (disc[i] == -1) {
            DFS(i, adj, low, disc, presentInStack, mystack);
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
