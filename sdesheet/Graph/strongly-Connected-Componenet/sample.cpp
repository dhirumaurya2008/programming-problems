#include<bits/stdc++.h>
using namespace std;
#define V 6
#define pb push_back

unordered_map<int,vector<int>> adj;

void DFS(int u,vector<int>& disc,vector<int>& low,stack<int>& mystack,vector<bool>& presentInStack)
{
	static int time = 0;
	//cout << " DFS ( " << u << " )" << endl;
	disc[u] = low[u] = time;
	time+=1;
	mystack.push(u);
	presentInStack[u] = true;

	for(int v : adj[u])
	{
		if(disc[v]==-1)	//If v is not visited
		{
			DFS(v,disc,low,mystack,presentInStack);
			low[u] = min(low[u],low[v]);
		}
		//Differentiate back-edge and cross-edge
		else if(presentInStack[v])	//Back-edge case
			low[u] = min(low[u],disc[v]);
	}

	if(low[u]==disc[u])	//If u is head node of SCC
	{
		cout<<"SCC is: ";
		while(mystack.top()!=u)
		{
			cout<<mystack.top()<<" ";
			presentInStack[mystack.top()] = false;
			mystack.pop();
		}
		cout<<mystack.top()<<"\n";
		presentInStack[mystack.top()] = false;
		mystack.pop();
	}
}

void findSCCs_Tarjan()
{
	vector<int> disc(V+1,-1),low(V+1,-1);
	vector<bool> presentInStack(V+1,false);	//Avoids cross-edge
	stack<int> mystack;

	for(int i=1;i<V+1;i++) {
       // cout << "Calling DFS for : " << i << endl;
		if(disc[i]==-1)
			DFS(i,disc,low,mystack,presentInStack);
	}
}

int main()
{
	adj[1].push_back(3);
	adj[2].push_back(1);
	adj[3].push_back(2);
	adj[3].push_back(5);
	adj[4].push_back(6);
	adj[5].push_back(4);
	adj[6].push_back(5);

	findSCCs_Tarjan();
	return 0;
}
