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
bool BST_Insert(BSTNode *&t, ElemType k);
void Create_BST(BST_Tree &t, ElemType a[], int n);
void output(BSTNode *t, ElemType k);

int main()
{
    BST_Tree t;
    Create_BST(t, a, alen);
    output(t.tree, 8);
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

void output(BSTNode *t, ElemType k)
{
    if (!t)
        return ;
    if (t->rchild)
        output(t->rchild, k);
    if (t->data >= k)
        std::cout << t->data << " ";
    if (t->lchild)
        output(t->lchild, k);
}