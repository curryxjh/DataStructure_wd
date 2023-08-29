#include <iostream>
const int MaxV = 110;

struct MGraph
{
    int numV, numE;
    char VList[MaxV];
    int edge[MaxV][MaxV];
};
bool IsExist(MGraph g);

int main()
{
    MGraph g;
    g.numV = 5;
    for (int i = 0; i < 5; ++ i)
        for (int j = 0; j < 5; ++ j)
            std::cin >> g.edge[i][j];
    std::cout << IsExist(g) << std::endl;
    return 0;
}

bool IsExist(MGraph g)
{
    int num = 0;
    for (int i = 0; i < g.numV; ++ i)
    {
        int degree = 0;
        for (int j = 0; j < g.numV; ++ j)
            degree += g.edge[i][j];
        if (degree % 2)
            ++ num;
    }
    return num == 0 || num == 2;
}