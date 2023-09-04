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
int Stack[N];
bool visited[N];
int top = 0;
bool Init(LGraph *g, int nsize);
bool Insert(LGraph *g, int u, int v, ElemType w);
bool Exist(LGraph *g, int u, int v);
void BFS(LGraph g, int v, bool visited[]);
bool BFSGraph(LGraph g, int u, int v);
void DFS(LGraph g, int u, int v);

int main()
{
    LGraph g;
    Init(&g, 6);
    Insert(&g, 1, 2, 0);
    Insert(&g, 2, 1, 0);
    Insert(&g, 2, 3, 0);
    Insert(&g, 3, 2, 0);
    Insert(&g, 1, 6, 0);
    Insert(&g, 6, 1, 0);
    Insert(&g, 6, 2, 0);
    Insert(&g, 2, 6, 0);
    Insert(&g, 5, 6, 0);
    Insert(&g, 6, 5, 0);
    Insert(&g, 3, 5, 0);
    Insert(&g, 5, 3, 0);
    Insert(&g, 7, 5, 0);
    Insert(&g, 5, 7, 0);
    DFS(g, 1, 5);
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

void DFS(LGraph g, int u, int v)
{
    if (u == v && !visited[u])
    {
        for (int i = 1; i <= top; ++ i)
            std::cout << Stack[i] << " ";
        std::cout << v << " ";
        puts("");
        return ;
    }
    visited[u] = true;
    Stack[ ++ top] = u;
    for (Enode *w = g.a[u]; w; w = w->nextArc)
    {
        if (! visited[w->adjVEx])
            DFS(g, w->adjVEx, v);
    }
    visited[u] = false;
    -- top;
}
