#include <iostream>
using namespace std;
const int MaxSize = 110;

struct SqBiTree
{
    int sqBiTNode[MaxSize];
    int ElemNum;
};

bool isBST(SqBiTree tree);
int a[10] = {40, 25, 60, -1, 30, -1,  80, -1, -1, 27};
int b[11] = {40, 50, 60, -1, 30, -1, -1, -1, -1, -1, 35};

int main()
{
    SqBiTree t1, t2;
    for (int i = 0; i < 10; ++ i)
        t1.sqBiTNode[i] = a[i];
    for (int i = 0; i < 11; ++ i)
        t2.sqBiTNode[i] = b[i];
    t1.ElemNum = 10;
    t2.ElemNum = 11;
    cout << "tree1: ";
    if (isBST(t1))
        puts("YES");
    else
        puts("NO");
    cout << "tree2: ";
    if (isBST(t2))
        puts("YES");
    else
        puts("NO");


    return 0;
}

bool isBST(SqBiTree tree)
{
    int *pmin, *pmax;
    pmin = new int[tree.ElemNum];
    pmax = new int[tree.ElemNum];
    for (int i = 0; i < tree.ElemNum; ++ i)
        pmin[i] = pmax[i] = tree.sqBiTNode[i];
    for (int i = tree.ElemNum - 1; i > 0; -- i)
    {
        if (tree.sqBiTNode[i] != -1)
        {
            int m = (i - 1) / 2;
            if (i % 2 == 1 && tree.sqBiTNode[m] > pmax[i])
                pmin[m] = pmin[i];
            else if (i % 2 == 0 && tree.sqBiTNode[m] < pmin[i])
                pmax[m] = pmax[i];
            else
                return false;
        }
    }
    return true;
}