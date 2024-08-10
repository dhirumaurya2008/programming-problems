#include<bits/stdc++.h>
using namespace std;
#define INF 99999

void printSolution(vector<vector<int>> &graph, int V) {

    for (int i =0; i<V; i++) {
        for (int j = 0; j< V; j++) {
            cout << graph[i][j] << " | ";
        }
        cout << endl;
    }
}

void floydWarshall(vector<vector<int>> &graph, int V) {

    for (int k=0; k<V; k++) {

        for (int i =0; i<V; i++) {
            for (int j = 0; j<V; j++) {
                graph[i][j] = min( graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
    printSolution(graph, 4);
}

int main()
{
    /* Let us create the following weighted graph
            10
    (0)------->(3)
        |     /|\
    5 |     |
        |     | 1
    \|/     |
    (1)------->(2)
            3     */
    vector<vector<int>> graph = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };

    // Print the solution
    floydWarshall(graph, 4);
    return 0;
}
