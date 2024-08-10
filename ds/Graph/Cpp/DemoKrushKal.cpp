#include<iostream>
#include<cstdlib>

using namespace std;

#define MAX_SET_SIZE 10

typedef struct _set_union
{

 int parrent[MAX_SET_SIZE];
 int sz[MAX_SET_SIZE];
 int n;
}set_union_t;

typedef struct _edge_pair
{
 int src;
 int dst;
 int weight;

}edge_pair_t;

typedef struct _Graph
{
 int nvertices;
 int nedges;
 edge_pair_t *edge;
}Graph_t;

Graph_t* createGraph(int V, int E)
{
  Graph_t* graph = (Graph_t*)malloc(sizeof(Graph_t));
  graph->nvertices = V;
  graph->nedges   = E;
  graph->edge = (edge_pair_t*)malloc(sizeof(edge_pair_t)*graph->nedges);
  return graph;
}

int root(set_union_t*s, int i)
{
    //cout << "Test 1root  p= " << i << endl;
    while(i != s->parrent[i] )
    {
      //   cout << "Test 2 root  p= " << i << endl;
        i = s->parrent[i];
    }
    return i;
}

bool connected(set_union_t*s, int p, int q)
{
   // cout << "connected  p= " << p << " , q= " << q << endl;
    return (root(s, p) == root(s, q));
}

void unionElem(set_union_t*s, int p, int q)
{
    int i = root(s, p);
    int j = root(s, q);

    if(i == j)
        return;

    if(s->sz[i] > s->sz[j])
    {
      s->parrent[j] = i;
      s->sz[i] = s->sz[i] + s->sz[j];
    }
    else
    {
              s->parrent[i] = j;
              s->sz[j] = s->sz[j] + s->sz[i];
    }
}

void set_union_init(set_union_t* s)
{
    for(int i=0; i<s->n; i++)
    {
        s->parrent[i] = i;
        s->sz[i]      = 1;
    }
}

set_union_t *createSetUnion(int n)
{
    set_union_t *s = (set_union_t *)malloc(sizeof(set_union_t));
    s->n = n;
    set_union_init(s);
    return s;
}

int weight_compare (const void * a, const void * b) {
   return ( ((edge_pair_t*)a)->weight - ((edge_pair_t*)b)->weight);
}

int KrushkalMST(Graph_t* graph)
{
   int weight =0;

   set_union_t *s = createSetUnion(graph->nvertices);
   cout << endl << endl;
     for(int i=0; i<graph->nedges; i++)
   {
        cout << " edge ( "  << graph->edge[i].src << ", " <<  graph->edge[i].dst<< ", " <<  graph->edge[i].weight<< " )" << endl;
   }
   qsort(graph->edge, graph->nedges, sizeof(edge_pair_t), weight_compare);

    cout << endl << endl;
    cout << "Edges now gets sorted: " <<  graph->nedges<< endl;
        for(int i=0; i<graph->nedges; i++)
   {
        cout << " edge ( "  << graph->edge[i].src << ", " <<  graph->edge[i].dst<< ", " <<  graph->edge[i].weight<< " )" << endl;
   }

   cout << "set and union created" <<  endl;
   #if 0
   //qsort(&(graph->edge), graph->nedges, sizeof(edge_pair_t), weight_compare);

  for(int i=0; i<graph->nedges; i++)
   {
        cout << " edge ( "  << graph->edge[i].src << ", " <<  graph->edge[i].dst<< " )" << endl;
   }
  #endif


   for(int i=0; i<graph->nedges; i++)
   {
     cout << " edge " << "( " << graph->edge[i].src << ", " <<  graph->edge[i].dst<< " )" << endl;
     if(!connected(s, graph->edge[i].src, graph->edge[i].dst)  )
     {
         unionElem(s, graph->edge[i].src, graph->edge[i].dst);

         cout << "Not connected edge " << "( " << graph->edge[i].src << ", " <<  graph->edge[i].dst<< " )" << endl;
         weight = weight + graph->edge[i].weight;
     }
   }

   return weight;

}


int main()
{
  int V, E;
  Graph_t *graph = createGraph(4, 5);
   // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dst = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dst = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dst = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dst = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dst = 3;
    graph->edge[4].weight = 4;

    cout << "MST weight is " << KrushkalMST(graph) << endl;
    cout << "Dhiru << " << 0 % 5;
 return 0;
}
