/*
 * 05
 */
#include <iostream>
using namespace std;
typedef char ElemType;

struct CSNode
{
    ElemType data;
    CSNode *firstchild, *nextsibling;
};
struct CSTree
{
    CSNode *root;
};

void BuildTree(CSNode *&r);
// ABD#E##C##FG###
int Height(CSNode *&r);

int main()
{
    CSTree tree;
    BuildTree(tree.root);
    cout << "height: " << Height(tree.root) << endl;
    return 0;
}

void BuildTree(CSNode *&r)
{
    ElemType ch;
    ch = getchar();
    if (ch == '#')
    {
        r = NULL;
        return ;
    }
    else
    {
        r = new CSNode;
        r->data = ch;
        r->firstchild = r->nextsibling = NULL;
        BuildTree(r->firstchild);
        BuildTree(r->nextsibling);
    }
}

int Height(CSNode *&r)
{
    if (! r)
        return 0;
    else
    {
        int ltree = Height(r->firstchild);
        int rtree = Height(r->nextsibling);
        if (ltree + 1 > rtree)
            return ltree + 1;
        else
            return rtree;
    }
}