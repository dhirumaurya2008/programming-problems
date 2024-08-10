#include<iostream>
#include<stdbool.h>

using namespace std;

#define MAXV 5

typedef struct _edgenode
{
    int y;
    int weight;
    struct _edgenode* next;
}edgenode;

typedef struct _graph
{
    edgenode *edges[MAXV];
    int       degree[MAXV];
    int       nvertices;
    int       nedges;
    bool      directed;
}graph;

void initialize_graph(graph *g, bool directed)
{
    g->nvertices = 0;
    g->nedges    = 0;
    g->directed  = directed;

    for(int i=0; i<MAXV; i++)
    {
            g->edges[i]  = NULL;
            g->degree[i] = 0;
    }
}

void insert_edge(graph *g, int x, int y, bool directed)
{
    edgenode* p = (edgenode*)malloc(sizeof(edgenode));
    if(!p)
        return;
    p->y = y;
    p->weight = 0;
    p->next  = g->edges[x];

    g->edges[x] = p;

    if(!directed)
        insert_edge(g, y, x, true);
    else
        g->degree[x]++;
}

void print_graph(graph *g)
{
    edgenode * p = NULL;
    for(int i=0; i<MAXV; i++)
    {
        cout<< "Adjacency List "<< i << " : " << endl;
        p = g->edges[i];

        while(p)
        {
           cout << " " << p->y ;
           p = p->next;
        }
        cout << endl;
    }
}

int main()
{
    graph *g = (graph*)malloc(sizeof(graph));
    initialize_graph(g, 0);
    insert_edge(g , 0, 1, false );
    insert_edge(g, 0, 4, false );
    insert_edge(g, 1, 2, false );
    insert_edge(g, 1, 3, false );
    insert_edge(g, 1, 4, false ) ;
    insert_edge(g, 2, 3, false );
    insert_edge(g, 3, 4, false );

    print_graph(g);

    free(g);
}
