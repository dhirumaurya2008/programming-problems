#include<bits/stdc++.h>
using namespace std;

typedef struct _DisjSet {
    int *parrent;
    int *rank;
    int nEle;
}DisjSet;

void initUF(DisjSet *djs, int nEle) {

    djs->parrent = (int*)malloc(sizeof(int) * nEle);
    djs->rank = (int*)malloc(sizeof(int) * nEle);
    djs->nEle = nEle;

    for (int i = 0; i<nEle; i++) {
        djs->parrent[i] = i;
        djs->rank[i] = 1;
    }
}

int findParrent(DisjSet *djs, int p) {

    if (p == djs->parrent[p])
        return p;

    return (djs->parrent[p] = findParrent(djs, djs->parrent[p]));
}

void doUnion(DisjSet *djs, int p, int q) {

    int parrent_p = findParrent(djs, p);
    int parrent_q = findParrent(djs, q);

    if (djs->rank[parrent_p] == djs->rank[parrent_q]) {
        djs->parrent[parrent_q] = djs->parrent[parrent_p];
        djs->rank[parrent_p] = djs->rank[parrent_p] + 1;
    }
    else if (djs->rank[parrent_p] > djs->rank[parrent_q]){
        djs->parrent[parrent_q] = djs->parrent[parrent_p];
    }
    else if (djs->rank[parrent_p] < djs->rank[parrent_q])
    {
        djs->parrent[parrent_p] = djs->parrent[parrent_q];
    }

}

int main()
{
    DisjSet djs;

    initUF(&djs, 5);

    doUnion(&djs,0, 2);
    doUnion(&djs,4, 2);
    doUnion(&djs,3, 1);
    if (findParrent(&djs,4) == findParrent(&djs, 0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (findParrent(&djs,1) == findParrent(&djs, 0))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
