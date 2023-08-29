/*
 * p04
 */
#include <iostream>
typedef char VertexType;
typedef int EdgeType;
const int MaxVertexNum = 110;
const int M = 110, N = 110;
struct ArcNode
{
    int adjvex; //弧所指向节点
    ArcNode *ne; //下一条弧
};

struct VNode
{
    VertexType data; // 顶点信息
    ArcNode *first;
};

struct ALGraph
{
    VNode vertices[MaxVertexNum];
    int vexnum, arcnum;
};

void convet(ALGraph &g, int mg[M][N]);

int main()
{

    return 0;
}


void convet(ALGraph &g, int mg[M][N])
{
    for (int i = 0; i < g.vexnum; ++ i)
    {
        ArcNode *p = g.vertices[i].first;
        while (p)
        {
            mg[i][p->adjvex] = 1;
            p = p->ne;
        }
    }
}