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
// ����
void BuildTree(TBNode *&r);
// ������
void InThread(TBNode *&r, TBNode *& pre);
// ��װ����������
void CreateeInTread(TBNode *&r);
//  ��������������������һ���ڵ�
TBNode* LastNode(TBNode *r);
// ����������������нڵ�p��ǰ��
TBNode* FrontNode(TBNode *p);
void inorder(TBNode* r);

int main()
{
    TBTree tree;
    BuildTree(tree.root);
    cout << "���������";
    inorder(tree.root);
    puts("");
    CreateeInTread(tree.root);
    cout << "���ڵ��ǰ����" << FrontNode(tree.root)->data << endl;

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