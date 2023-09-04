#include <iostream>
#include <cstring>
typedef int ElemType;
const int N = 110;
struct Enode
{
    int adjVEx;
    ElemType w;
    Enode *nextArc;
};

struct LGraph
{
    int n;
    int e;
    Enode **a;
};
bool Init(LGraph *g, int nsize);
bool Insert(LGraph *g, int u, int v, ElemType w);
bool Exist(LGraph *g, int u, int v);
void DFS(LGraph g, int v, bool visited[]);
bool DFSGraph(LGraph g, int u, int v);
void BFS(LGraph g, int v, bool visited[]);
bool BFSGraph(LGraph g, int u, int v);


int main()
{
    LGraph g;
    Init(&g, 6);
    Insert(&g, 1, 2, 0);
    Insert(&g, 1, 3, 0);
    Insert(&g, 2, 4, 0);
    Insert(&g, 2, 5, 0);
    Insert(&g, 4, 6, 0);
    Insert(&g, 6, 4, 0);
    Insert(&g, 4, 2, 0);
    Insert(&g, 5, 2, 0);
    Insert(&g, 3, 1, 0);
    Insert(&g, 2, 1, 0);
    if (DFSGraph(g, 1, 4))
        puts("DFS:  YES");
    else
        puts("DFS:  NO");
    if (BFSGraph(g, 1, 4))
        puts("BFS:  YES");
    else
        puts("BFS:  NO");
    return 0;
}

bool Init(LGraph *g, int nsize)
{
    g->n = nsize;
    g->e = 0;
    g->a = (Enode**)malloc(nsize * sizeof(Enode*));
    if (!g->a)
        return false;
    else
    {
        for (int i = 1; i <= g->n; ++ i)
            g->a[i] = NULL;
        return true;
    }
}

bool Exist(LGraph *g, int u, int v)
{
    Enode *p;
    if (u < 1 || v < 1 || u > g->n || v > g->n || u == v)
        return false;
    p = g->a[u];
    while (p && p->adjVEx != v)
        p = p->nextArc;
    if (!p)
        return false;
    return true;
}


bool Insert(LGraph *g, int u, int v, ElemType w)
{
    Enode *p;
    if (u < 1 || v < 1 || u > g->n || v > g->n || u == v)
        return false;
    if (Exist(g, u, v))
        return false;
    p = new Enode;
    p->adjVEx = v;
    p->w = w;
    p->nextArc = g->a[u];
    g->a[u] = p;
    ++ g->e;
    return true;
}

void DFS(LGraph g, int v, bool visited[])
{
    Enode *w;
    std::cout << v << " ";
    visited[v] = true;
    for (w = g.a[v]; w; w = w->nextArc)
        if (! visited[w->adjVEx])
            DFS(g, w->adjVEx, visited);
}

bool DFSGraph(LGraph g, int u, int v)
{
    bool *visited = new bool[g.n + 1];
//    memset(visited, 0, sizeof  visited);
    for (int i = 1; i <= g.n; ++ i)
        visited[i] = false;
    DFS(g, u, visited);
    return visited[v];
}

void BFS(LGraph g, int v, bool visited[])
{
    Enode *w;
    int *q = new int[g.n + 1];
    int hh = 0, tt = -1;
    q[++ tt] = v;
    visited[v] = true;
    while(hh <= tt)
    {
        int t = q[hh ++];
        std::cout << t << " ";
        for (w = g.a[t]; w; w = w->nextArc)
        {
            if (! visited[w->adjVEx])
            {
                visited[w->adjVEx] = true;
                q[++ tt] = w->adjVEx;
            }
        }
    }
}

bool BFSGraph(LGraph g, int u, int v)
{
    bool *visited = new bool[g.n + 1];
    for (int i = 1; i <= g.n; ++ i)
        visited[i] = false;
    BFS(g, u, visited);
    return visited[v];
}