class SetUnion
{
public:
    int parrent;
    int sized;
};

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


int main()
{
    SetUnion1* s= createSetUnion(graph->nvertices);

}
