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
// ����������������������еĵ�һ���ڵ�
TBNode* FirstNode(TBNode *r);
// ����������������нڵ�p�����е���һ�����
TBNode* NextNode(TBNode *p);
//  ��������������������һ���ڵ�
TBNode* LastNode(TBNode *r);
// ����������������нڵ�p��ǰ��
TBNode* FrontNode(TBNode *p);
// �������
void inorder(TBNode *r);
// ����ͷ�ڵ���������
void Inorder(TBNode *r);

int main()
{
    TBTree tree;
    BuildTree(tree.root);
    cout << "���������";
    inorder(tree.root);
    puts("");
    CreateeInTread(tree.root);
    cout << "���������һ���ڵ㣺" << FirstNode(tree.root)->data << endl;
    cout << "����������һ���ڵ㣺" << LastNode(tree.root)->data << endl;
    cout << "���ڵ��ǰ����" << FrontNode(tree.root)->data << endl;
    cout << "���ڵ�ú�̣�" << NextNode(tree.root)->data << endl;
    cout << "����ͷ�������������";
    Inorder(tree.root);
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

void Inorder(TBNode *r)
{
    for (TBNode* p = FirstNode(r); p != NULL; p = NextNode(p))
        cout << p->data << " ";
}