#include<bits/stdc++.h>
using namespace std;

typedef struct _Node {
    int mSrc;
    int mDst;
    int mWt;
    _Node(int src, int dst, int wt) {
        mSrc = src;
        mDst = dst;
        mWt = wt;
    }
}Node;

int makeSet (vector<int> &parrent, vector<int> &rank, int element) {

    for (int i = 0; i<element; i++) {
        parrent[i] = i;
        rank[i] = 1;
    }
}

/*This function will provide us the parrent of p*/
int findParrent(vector<int> &parrent, int p){

    if (p == parrent[p])
        return p;

    return (parrent[p] = findParrent(parrent, parrent[p]));
}

void doUnion(vector<int> &parrent, vector<int> &rank, int p, int q) {

    int p_p = findParrent(parrent, p);
    int p_q = findParrent(parrent, q);

    if (rank[p_p] == rank[p_q]) {
        parrent[p_q] = parrent[p_p];
        rank[p_p]++;
    }
    else if (rank[p_p] > rank[p_q]) {
        parrent[p_q] = parrent[p_p];
    }
     else if (rank[p_p] < rank[p_q]) {
        parrent[p_p] = parrent[p_q];
    }
}

bool comp(Node &n1, Node &n2) {
    return (n1.mWt < n2.mWt);
}

int mstKrushKal(vector<Node> &edgeList, int V)
{

  vector<int> parrent(V);
  vector<int> rank(V);
  vector<pair<int, int>> mst;
  makeSet(parrent, rank, V);
  sort(edgeList.begin(), edgeList.end(), comp);
  int mCost = 0;

  for (auto it : edgeList) {

    int pSrc = findParrent(parrent, it.mSrc);
    int pDst = findParrent(parrent, it.mDst);

    if (pSrc != pDst) {
        mCost += it.mWt;
        mst.push_back({it.mSrc,it.mDst });
        doUnion(parrent, rank,it.mSrc, it.mDst);
    }
  }

  return mCost;
}

int main() {
    vector<Node> edges;
    edges.push_back(Node(0,1,2));
	edges.push_back(Node(0,3,6));
	edges.push_back(Node(1,0,2));
	edges.push_back(Node(1,2,3));
	edges.push_back(Node(1,3,8));
	edges.push_back(Node(1,4,5));
	edges.push_back(Node(2,1,3));
	edges.push_back(Node(2,4,7));
	edges.push_back(Node(3,0,6));
	edges.push_back(Node(3,1,8));
	edges.push_back(Node(4,1,5));
	edges.push_back(Node(4,2,7));

    cout << "Cost of mst using Krushkal Algorithm is " << mstKrushKal(edges, 5);
    return 0;
}
