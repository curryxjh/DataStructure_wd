#include <iostream>
typedef int ElemType;
struct BSTNode
{
    ElemType data;
    BSTNode *lchild, *rchild;
};

struct BST_Tree
{
    BSTNode *tree;
};

int a[12] = {17,12,19,10,15,18,25,8,11,13,16,22};
int alen = 12;
int predt = -0x3f3f3f3f;
bool BST_Insert(BSTNode *&t, ElemType k);
void Create_BST(BST_Tree &t, ElemType a[], int n);
BSTNode* BST_Search(BSTNode *t, ElemType k);
bool DeleteBSTNode(BSTNode *&t, ElemType k);
bool JudgeBST(BSTNode *&t);
// todo 写一个非二叉排序树去测试
int main()
{
    BST_Tree t;
    Create_BST(t, a, alen);
    if (JudgeBST(t.tree))
        puts("YES");
    else
        puts("NO");
    return 0;
}

bool BST_Insert(BSTNode *&t, ElemType k)
{
    if (!t)
    {
        t = new BSTNode;
        t->data = k;
        t->lchild = t->rchild = NULL;
        return true;
    }
    else if (k == t->data)
        return false;
    else if (k < t->data)
        return BST_Insert(t->lchild, k);
    else
        return BST_Insert(t->rchild, k);
}

void Create_BST(BST_Tree &t, ElemType a[], int n)
{
    t.tree = NULL;
    for (int i = 0; i < n; ++ i)
        BST_Insert(t.tree, a[i]);
}

BSTNode* BST_Search(BSTNode *t, ElemType k)
{
    while (t && t->data != k)
    {
        if (k < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return t;
}

bool DeleteBSTNode(BSTNode *&t, ElemType k)
{
    if(! t)
        return false;
    BSTNode *p = t, *pre;
    while (p && p->data != k)
    {
        pre = p;
        if (p->data > k)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if (! p)
        return false;
    if (p->lchild && p->rchild)
    {
        BSTNode *minnode = p->rchild;
        pre = p;
        while (minnode->lchild) // 找右子树中最小值
        {
            pre = minnode;
            minnode = minnode->lchild;
        }
        p->data = minnode->data;
        if (pre->rchild == minnode)
            pre->rchild = minnode->rchild;
        else
        {
            pre->lchild = minnode->rchild;
            free(minnode);
            minnode = NULL;
        }
    }
    else // 此处p仅有一个儿子
    {
        if (pre->lchild = p) // p->rchild = NULL
            pre->lchild = p->lchild ? p->lchild : p->rchild;
        else if (pre->rchild = p) // p->lchild = NULL
            pre->rchild = p->lchild ? p->lchild : p->rchild;
        free(p);
        p = NULL;
    }
    return true;
}

bool JudgeBST(BSTNode *&t)
{
    if (!t)
        return true;
    else
    {
        bool f1 = JudgeBST(t->lchild);
        if (! f1 || predt >= t->data)
            return false;
        predt = t->data;
        bool f2 = JudgeBST(t->rchild);
        return f2;
    }
}