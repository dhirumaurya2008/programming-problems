#include<bits/stdc++.h>
using namespace std;

struct edge{
	int src,dst,wt;
	edge(int in_src, int in_dst, int in_wt) {
        src = in_src;
        dst = in_dst;
        wt  = in_wt;
    }
};
int V,E;

void bellmanFord(vector<edge>& Edges)
{
	int parent[V];		//Stores Shortest Path Structure
	int cost_parent[V];	//Cost of the node to parent edge weight
	vector<int> value(V,INT_MAX);	//Keeps shortest path values to each vertex from source

	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	//Include (V-1) edges to cover all V-vertices
	bool updated;
	for(int i=0;i<V-1;++i)
	{
		updated = false;
		for(int j=0;j<E;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(value[U]!=INT_MAX and value[U]+wt<value[V])
			{
				value[V] = value[U]+wt;
				parent[V] = U;
				cost_parent[V] = value[V];
				updated = true;
			}
		}
		if(updated==false)
			break;
	}
	//Now check by relaxing once more if we have a negative edge cycle
	for(int j=0;j<E and updated==true;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(value[U]!=INT_MAX and value[U]+wt<value[V])
			{
				cout<<"Graph has -VE edge cycle\n";
				return;
			}
		}
	//Print Shortest Path Graph
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<parent[i]<<"from source 0 = "<<value[i]<<"\n";
}

int main()
{

	vector<edge> edges;

	//Now input all E edges
	int src,dst,wt;
    edges.push_back(edge(0,1,5));
	edges.push_back(edge(1,2,-2));
	edges.push_back(edge(1,5,-3));
	edges.push_back(edge(2,4,3));
	edges.push_back(edge(3,2,6));
	edges.push_back(edge(3,4,-2));
	edges.push_back(edge(5,3,1));

	bellmanFord(edges);
	return 0;
}

//TIME COMPLEXITY: O(V.E)
