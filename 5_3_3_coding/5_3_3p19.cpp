#include <iostream>
using namespace std;
typedef char ElemType;
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

int main()
{
    Tree tree;
    BuildTree(tree.root);
    cout << "带权路径长度为：" << WPL(tree.root, 0) << endl;
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
