#include<iostream>
#include<stdbool.h>
#include<queue>
#include<vector>

using namespace std;

#define MAXV 9

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
    g->nvertices = MAXV;
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

void insert_edge(graph *g, int x, int y, bool directed, int weight)
{
    edgenode* p = (edgenode*)malloc(sizeof(edgenode));
    if(!p)
        return;
    p->y = y;
    p->weight = weight;
    p->next  = g->edges[x];

    g->edges[x] = p;

    if(!directed)
        insert_edge(g, y, x, true, weight);
    else
        g->degree[x]++;
}

void print_graph(graph *g)
{
    edgenode * p = NULL;
    for(int i=0; i<MAXV; i++)
    {
        //cout<< "Adjacency List "<< i << " : " << endl;
        p = g->edges[i];

        while(p)
        {
           cout << "( " << i << " , " <<p->y << " , " << p->weight << ")" << endl;
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

int Dijikstra( graph *g, int src)
{
   // cout << "TEST-0 : " << src << endl;
    vector<bool> inTree(g->nvertices, false);
    //cout << "TEST-2 : " << src << endl;
    vector<int>  parrent(g->nvertices, -1);
    //cout << "TEST-3 : " << src << endl;
    vector<int>  distance_d(g->nvertices, INT_MAX);
    //cout << "TEST-4 : " << src << endl;
    edgenode *p = NULL;
    //cout << "TEST-5 : " << src << endl;
    int w, nextChoosenVertex, weight =0, dist;
    //cout << "TEST-6 : " << src << endl;

    nextChoosenVertex = src;
    //cout << "TEST-7 : " << src << endl;
    distance_d[src] = 0;
    //cout << "TEST-8 : " << src << endl;

    while(!inTree[nextChoosenVertex])
    {
        cout << "nextChoosenVertex : " << nextChoosenVertex << endl;
        inTree[nextChoosenVertex] = true;

        if(nextChoosenVertex != src)
        {
            weight = weight + dist;
        }

        p = g->edges[nextChoosenVertex];

        while(p)
        {
            w = p->y;
            cout << "w = " << w << " distance_d[w] = " << distance_d[w] << " p->weight = " << p->weight << " distance_d[nextChoosenVertex] " << distance_d[nextChoosenVertex] << endl;
            if(distance_d[w] > (p->weight + distance_d[nextChoosenVertex]))
            {
                 cout << "TEST -1 w = " << w << " distance_d[w] = " << distance_d[w] << " p->weight = " << p->weight << " distance_d[nextChoosenVertex] " << distance_d[nextChoosenVertex] << endl;
                distance_d[w] = p->weight + distance_d[nextChoosenVertex];
                cout << " TEST -2 w = " << w << " distance_d[w] = " << distance_d[w] << " p->weight = " << p->weight << " distance_d[nextChoosenVertex] " << distance_d[nextChoosenVertex] << endl;
                parrent[w] = nextChoosenVertex;

            }
            p = p->next;
        }

        dist = INT_MAX;

        for(int i=0; i<g->nvertices; i++)
        {
            if((dist > distance_d[i]) && (!inTree[i]))
            {
                dist = distance_d[i];
                nextChoosenVertex = i;
            }
        }

    }

   for(int i=0; i<g->nvertices; i++)
        {
           cout << "(" << src << " ," << i <<  " ) = " << distance_d[i] << endl;
        }
    return weight;
}

int main()
{
    graph *g = (graph*)malloc(sizeof(graph));
    initialize_graph(g, 0);
      insert_edge(g, 0, 1, false,4);
     insert_edge(g, 0, 7, false,8);
     insert_edge(g, 1, 2, false,8);
     insert_edge(g, 1, 7,false, 11);
     insert_edge(g, 2, 3,false, 7);
     insert_edge(g, 2, 8, false,2);
     insert_edge(g, 2, 5, false,4);
     insert_edge(g, 3, 4, false,9);
     insert_edge(g, 3, 5, false,14);
     insert_edge(g, 4, 5, false,10);
     insert_edge(g, 5, 6, false,2);
     insert_edge(g, 6, 7, false,1);
     insert_edge(g, 6, 8, false,6);
     insert_edge(g, 7, 8, false,7);

    #if 0
    insert_edge(g , 0, 1, false, 10 );
    insert_edge(g, 0, 3, false,  5 );
    insert_edge(g, 0, 2, false , 6);

    insert_edge(g, 1, 3, false, 15 );
    insert_edge(g, 2, 3, false, 4);
    #endif

    print_graph(g);

    cout << endl << "primsMSTAlgorithm: " <<  Dijikstra(g, 0) << endl;

    //BFS(g, 2);


    free(g);
}
