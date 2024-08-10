#include<bits/stdc++.h>
using namespace std;

struct EdgeNode {
    int src;
    int dst;
    int wt;
    EdgeNode(int in_src, int in_dst, int in_wt) {
        src = in_src;
        dst = in_dst;
        wt  = in_wt;
    }
};

void belMenFord(vector<EdgeNode> &edges, int V, int E) {
    vector<int> parrent(V, -1);
    vector<int> dist(V, INT_MAX);
   // vector<int> cost_parrent(V);

    parrent[0] = -1;
    dist[0] = 0;
    bool updated;
    for (int i =0; i<V-1; i++) {

        updated = false;

        for (auto it : edges) {
            int U = it.src;
            int V = it.dst;
            int wt = it.wt;

            if (dist[U] != INT_MAX && (dist[U] + wt) < dist[V]) {
                dist[V] = (dist[U] + wt);
                parrent[V] = U;
               // cost_parrent[V] = dist[V];
                updated = true;
            }
        }

        if (updated == false) {
            break;
        }
    }

    if (updated == true) {
     for (auto it : edges) {

                int U = it.src;
                int V = it.dst;
                int wt = it.wt;

                if (dist[U] != INT_MAX && (dist[U] + wt) < dist[V]) {
                    cout << "Negative edge weight cycle is present " << endl;
                }
        }
    }

    //Print SPG
    for (int i=0; i<V; i++) {
        cout << " U->V " << parrent[i] << " -> " << i << " cost to reach " << parrent[i] << " from source 0 = " << dist[i] << endl;
    }
}

int main() {
    int V = 6; //Number of vertices
    int E = 7; //Number of edges

    vector<EdgeNode> edges;
    edges.push_back(EdgeNode(0,1,5));
	edges.push_back(EdgeNode(1,2,-2));
	edges.push_back(EdgeNode(1,5,-3));
	edges.push_back(EdgeNode(2,4,3));
	edges.push_back(EdgeNode(3,2,6));
	edges.push_back(EdgeNode(3,4,-2));
	edges.push_back(EdgeNode(5,3,1));

	belMenFord(edges, V, E);

	return 0;
}
