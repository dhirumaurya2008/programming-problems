#include<iostream>
#include<stdbool.h>
#include<queue>

using namespace std;

#define MAXV 4

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
    bool       processed[MAXV];
    bool       discoverd[MAXV];
    int        parrent[MAXV];
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
            g->processed[i] = false;
            g->discoverd[i] = false;
            g->parrent[i] = -1;
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

void process_vertex_early(int v)
{
    cout << endl<< "processed vertex early" << v << endl;
}

void process_vertex_late(int v)
{
    //cout << "processed vertex late" << v << endl;
}

void process_edge(int x, int y)
{
    cout << endl<< "processed edge (" << x << y << ")" << endl;
}

void BFS(graph* g, int source)
{
    queue<int> que;

    g->discoverd[source] = true;
    que.push(source);

    /*Until Queue is not empty*/
    while(!que.empty())
    {
       /*pop the first elemnt*/
       int v = que.front();
       cout << v << " " ;
       //process_vertex_early(v);
       g->processed[v] = true;
       que.pop();
       /*Take the adjacency list of v and iterate until null*/
       edgenode* p = g->edges[v];
       while(p)
       {
           int y = p->y;

           /*Check if edge is processed in undirected or it is directed*/
           //if(g->processed[y] == false || g->directed)
            //process_edge(v, y);

           /*Check if vertex is undicovered*/
           if(g->discoverd[y] == false)
           {
               g->discoverd[y] = true;
               g->parrent[y] = v;
               que.push(y);
           }

           p = p->next;
       }

       //process_vertex_late(v);
    }

}


int main()
{
    graph *g = (graph*)malloc(sizeof(graph));
    initialize_graph(g, 0);
    insert_edge(g , 0, 1, false );
    insert_edge(g, 0, 2, false );
    insert_edge(g, 1, 2, false );

    insert_edge(g, 2, 0, false );
    insert_edge(g, 2, 3, false );
    insert_edge(g, 3, 3, false );

    print_graph(g);

    cout << endl << "BFS traversal" << endl ;
    BFS(g, 2);


    free(g);
}
