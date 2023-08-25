#include <iostream>
using namespace std;
typedef char ElemType;
const int MaxSize = 110;
struct TNode
{
    ElemType data;
    int weight;
    TNode *lchild, *rchild;
};
struct Tree
{
    TNode *root;
};
void BuildTree(TNode *&r);
int WPL(TNode *&r, int deep);
int WPL_Sequence(TNode *&r);

int main()
{
    Tree tree;
    BuildTree(tree.root);
    cout << "带权路径长度为(先序)：" << WPL(tree.root, 0) << endl;
    cout << "带权路径长度为(层序)：" << WPL_Sequence(tree.root) << endl;
    return 0;
}

void BuildTree(TNode *&r)
{
    ElemType  ch;
    cin >> ch;
    if (ch == '#')
    {
        r = NULL;
        return ;
    }
    else
    {
        r = new TNode;
        r->data = ch;
        r->weight = ch - '0';
        r->lchild = r->rchild = NULL;
        BuildTree(r->lchild);
        BuildTree(r->rchild);
    }
}

int WPL(TNode *&r, int deep)
{
    int wpl = 0;
    if (! r->lchild && ! r->rchild)
        wpl += deep * r->weight;
    if (r->lchild)
        wpl += WPL(r->lchild, deep + 1);
    if (r->rchild)
        wpl += WPL(r->rchild, deep + 1);
    return wpl;
}

int WPL_Sequence(TNode *&r)
{
    TNode* q[MaxSize];
    int hh = 0, tt = 0;
    int wpl = 0, deep = 0;
    TNode* lastNode;
    lastNode = r;
    TNode *nextLevelLastNode = NULL;
    q[tt ++] = r;
    while (hh < tt)
    {
        TNode* t = q[hh ++];
        if (! t->lchild && ! t->rchild)
            wpl += deep * t->weight;
        if (t->lchild)
        {
            q[tt ++] = t->lchild;
            nextLevelLastNode = t->lchild;
        }
        if (t->rchild)
        {
            q[tt ++] = t->rchild;
            nextLevelLastNode = t->rchild;
        }
        if (t == lastNode)
        {
            lastNode = nextLevelLastNode;
            ++ deep;
        }
    }
    return wpl;
}