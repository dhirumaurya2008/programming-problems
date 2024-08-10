// A simple representation of graph using STL
#include<bits/stdc++.h>
#include<queue>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
	for (int v = 0; v < V; ++v)
	{
		cout << "\n Adjacency list of vertex "
			<< v << "\n head ";
		for (auto x : adj[v])
		cout << "-> " << x;
		printf("\n");
	}
}

void BFS(vector<int> adj[], int V, int src)
{
   queue<int> que;
   vector<bool> visited(V, 0);
   que.push(src);
   visited[src] = true;

   while(!que.empty())
   {

       int f_queue = que.front();
       cout << f_queue << " " ;
       que.pop();
       for(auto itr: adj[f_queue])
       {
           if(!visited[itr]){
           visited[itr] = true ;
           que.push(itr);
           }
       }
   }


}

// Driver code
int main()
{
	int V = 4;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
    addEdge(adj,0, 2);
    addEdge(adj,1, 2);
    addEdge(adj,2, 0);
    addEdge(adj,2, 3);
    addEdge(adj,3, 3);
	//printGraph(adj, V);
	cout <<endl<< "Printing BFS Data Structure" <<  endl;
	BFS(adj, V, 2);
	return 0;
}
