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
void Destory(LGraph *g);
bool Insert(LGraph *g, int u, int v, ElemType w);
bool Exist(LGraph *g, int u, int v);
bool Remove(LGraph *g, int u, int v);
void DFS(LGraph *g, int v, int &vnum, int &ednum, bool visited[]);
bool IsTree(LGraph *g);

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
    if(IsTree(&g))
        puts("YES");
    else
        puts("NO");
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

void Destory(LGraph *g)
{
    for (int i = 1; i <= g->n; ++ i)
    {
        delete g->a[i];
        g->a[i] = NULL;
    }
    delete []g->a;
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

bool Remove(LGraph *g, int u, int v)
{
    Enode *p, *q;
    if (u < 1 || v < 1 || u > g->n || v > g->n || u == v)
        return false;
    p = g->a[u];
    q = NULL;
    while (p && p->adjVEx != v)
    {
        q = p;
        p = p->nextArc;
    }
    if (! p)
        return false;
    if (q)
        q->nextArc = p->nextArc;
    else
        g->a[u] = p->nextArc;
    free(p);
    -- g->e;
    return true;
}

void DFS(LGraph *g, int v, int &vnum, int &ednum, bool visited[])
{
    Enode *w;
    visited[v] = true;
    std::cout << v << " ";
    ++ vnum;
    for (w = g->a[v]; w; w = w->nextArc)
        if (! visited[w->adjVEx])
            DFS(g, w->adjVEx, vnum, ++ ednum, visited);
}

bool IsTree(LGraph *g)
{
    bool *visited = new bool[g->n + 1];
//    memset(visited, false, sizeof visited);
    for (int i = 1; i <= g->n; ++ i)
        visited[i] = false;
    int vnum = 0, ednum = 0;
    DFS(g, 1, vnum, ednum, visited);
    puts("");
//    std::cout << "DFS: " << vnum << " " << ednum << std::endl;
    if (vnum == g->n && ednum == (g->n - 1))
        return true;
    else
        return false;
}

