#include <iostream>
using namespace std;
struct TNode
{
    char data;
    TNode *lchild, *rchild;
};
struct Tree
{
    TNode *root;
};
void BuildTree(TNode *&r);
void Tran_to_exp(TNode *&r, int deep);

int main()
{
    Tree tree;
    BuildTree(tree.root);
    cout << "对应中缀表达式为： ";
    Tran_to_exp(tree.root, 1);
    return 0;
}


void BuildTree(TNode *&r)
{
    char ch;
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
        r->lchild = r->rchild = NULL;
        BuildTree(r->lchild);
        BuildTree(r->rchild);
    }
}

void Tran_to_exp(TNode *&r, int deep)
{
    if (! r)
        return ;
    else if (! r->lchild && ! r->rchild)
        cout << r->data;
    else
    {
        if (deep > 1)
            cout << "(";
        Tran_to_exp(r->lchild, deep + 1);
        cout << r->data;
        Tran_to_exp(r->rchild, deep + 1);
        if (deep > 1)
            cout << ')';
    }
}
