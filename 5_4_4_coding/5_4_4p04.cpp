/*
 * p04
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
int leaves(CSNode *&r);

int main()
{
    CSTree tree;
    BuildTree(tree.root);
    cout << "leaves:  " << leaves(tree.root) << endl;
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

int leaves(CSNode *&r)
{
    if (! r)
        return 0;
    if (! r->firstchild)
        return 1 + leaves(r->nextsibling);
    else if (r->firstchild)
        return leaves(r->firstchild) + leaves(r->nextsibling);
}