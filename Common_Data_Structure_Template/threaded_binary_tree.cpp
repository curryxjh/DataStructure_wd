#include <iostream>
using namespace std;
typedef char ElemType;
struct TBNode
{
    ElemType data;
    int ltag, rtag;
    TBNode *lchild, *rchild;
};
struct TBTree
{
    TBNode *root;
};
// 建树
void BuildTree(TBNode *&r);
// 线索化
void InThread(TBNode *&r, TBNode *& pre);
// 封装将树线索化
void CreateeInTread(TBNode *&r);
// 求中序遍历二叉树中序序列的第一个节点
TBNode* FirstNode(TBNode *r);
// 求中序遍历二叉树中节点p在序列的下一个后继
TBNode* NextNode(TBNode *p);
//  求中序遍历二叉树中最后一个节点
TBNode* LastNode(TBNode *r);
// 求中序遍历二叉树中节点p得前驱
TBNode* FrontNode(TBNode *p);
void inorder(TBNode* r);

int main()
{
    TBTree tree;
    BuildTree(tree.root);
    cout << "中序遍历：";
    inorder(tree.root);
    puts("");
    CreateeInTread(tree.root);
    cout << "中序遍历第一个节点：" << FirstNode(tree.root)->data << endl;
    cout << "中序遍历最后一个节点：" << LastNode(tree.root)->data << endl;
    cout << "根节点得前驱：" << FrontNode(tree.root)->data << endl;
    cout << "根节点得后继：" << NextNode(tree.root)->data << endl;
    return 0;
}

void BuildTree(TBNode *&r)
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
        r = new TBNode;
        r->data = ch;
        r->ltag = r->rtag = 0;
        r->lchild = NULL;
        r->rchild = NULL;
        BuildTree(r->lchild);
        BuildTree(r->rchild);
    }
}

void InThread(TBNode *&r, TBNode *& pre)
{
    if (r)
    {
        InThread(r->lchild, pre);
        if (! r->lchild)
        {
            r->lchild = pre;
            r->ltag = 1;
        }
        if (pre && ! pre->rchild)
        {
            pre->rchild = r;
            pre->rtag = 1;
        }
        pre = r;
        InThread(r->rchild, pre);
    }
}

void CreateeInTread(TBNode *&r)
{
    TBNode *pre = NULL;
    if (r)
    {
        InThread(r, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

TBNode* FirstNode(TBNode *r)
{
    while (r->ltag == 0)
        r = r->lchild;
    return r;
}

TBNode* NextNode(TBNode *p)
{
    if (p->rtag == 0)
        return FirstNode(p->rchild);
    else
        return p->rchild;
}

TBNode* LastNode(TBNode *r)
{
    while (r->rtag == 0)
        r = r->rchild;
    return r;
}

TBNode* FrontNode(TBNode *p)
{
    if (! p->ltag)
        return LastNode(p->lchild);
    else
        return p->lchild;
}

void inorder(TBNode* r)
{
    if (!r)
        return ;
    inorder(r->lchild);
    cout << r->data << " ";
    inorder(r->rchild);
}