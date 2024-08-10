#include<iostream>
//#include<vector>
#include<algorithm>

using namespace std;
class EdgePair
{
 public:
     int src;
     int dst;
     int weight;
};

class Graph
{
  public:
  int nvertices;
  int nedges;
  EdgePair *edges;
};


class SetUnion
{
public:
    int parrent;
    int sized;
};

Graph *createGraph(int V, int E)
{
    Graph *g = new Graph();

    g->nvertices = V;
    g->nedges    = E;

    g->edges   = new EdgePair[V];

    return g;
}

SetUnion* createSetUnion(int n)
{
    //cout << "\n Start createSetUnion " << n << endl;

    SetUnion *setUnion = new SetUnion[n*sizeof(SetUnion)];

    if(!setUnion)
    {
        cout << "Failed" << endl;
    }

    cout << " TEST \n" << endl;
    for(int i=0; i<n; i++)
    {
        cout << " TEST \n" << i << endl;
        setUnion[i]->parrent = i;
        setUnion[i]->sized = 1;
    }
    cout << "\n End createSetUnion " << n << endl;
    return setUnion;
}

int root(SetUnion*s, int i)
{
    while(i != s->parrent[i] )
    {
        i = s->parrent[i];
    }
    return i;
}

bool connected(SetUnion*s, int p, int q)
{
    return (root(s, p) == root(s, q));
}

void unionElem(SetUnion*s, int p, int q)
{
    int i = root(s, p);
    int j = root(s, q);

    if(i == j)
        return;

    if(s->sized[i] > s->sized[j])
    {
      s->parrent[j] = i;
      s->sized[i] = s->sized[i] + s->sized[j];
    }
    else
    {
              s->parrent[i] = j;
              s->sized[j] = s->sized[j] + s->sized[i];
    }
}

bool operator<(const EdgePair &x, const EdgePair &y) {
    if (x.weight < y.weight)
        return true;
    return false;
}

int KruskalMST(Graph *graph)
{
    int weight = 0;

     for (int i = 0; i < graph->nedges; ++i)
        cout << "\n src " << graph->edges[i].src << " dst " << graph->edges[i].dst << " weight  " << graph->edges[i].weight << endl;

   sort(graph->edges, (graph->edges + graph->nedges));

   cout << "\n After Sort \n" << endl;
   for (int i = 0; i < graph->nedges; ++i)
        cout << "src " << graph->edges[i].src << " dst " << graph->edges[i].dst << " weight  " << graph->edges[i].weight << endl;

         #if 1
   SetUnion1* s= createSetUnion(graph->nvertices);



   for(int i=0; i<graph->nedges; i++)
   {
      cout << "\n Checking Edge "  << " src " << graph->edges[i].src << " dst "  << graph->edges[i].dst << endl;
       if(!connected(s, graph->edges[i].src, graph->edges[i].dst))
       {
         unionElem(s, graph->edges[i].src, graph->edges[i].dst);
         weight = weight + graph->edges[i].weight;
       }
   }
   #endif

   return weight;
}

int main()
{
    int V = 4;
    int E = 5;
    Graph *graph = createGraph(V, E);

    // add edge 0-1
    graph->edges[0].src = 0;
    graph->edges[0].dst = 1;
    graph->edges[0].weight = 10;

    // add edge 0-2
    graph->edges[1].src = 0;
    graph->edges[1].dst = 2;
    graph->edges[1].weight = 6;

    // add edge 0-3
    graph->edges[2].src = 0;
    graph->edges[2].dst = 3;
    graph->edges[2].weight = 5;

    // add edge 1-3
    graph->edges[3].src = 1;
    graph->edges[3].dst = 3;
    graph->edges[3].weight = 15;

    // add edge 2-3
    graph->edges[4].src = 2;
    graph->edges[4].dst = 3;
    graph->edges[4].weight = 4;

   cout << "KruskalMST " << KruskalMST(graph);

}

