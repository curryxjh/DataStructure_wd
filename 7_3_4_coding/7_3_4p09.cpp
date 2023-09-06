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
BSTNode* BST_Search(BSTNode *t, ElemType k);
int find_max(BSTNode *t);
int find_min(BSTNode *t);


int main()
{
    BST_Tree t;
    Create_BST(t, a, alen);
    std:: cout << "max: " << find_max(t.tree) << "  " << "min:  " << find_min(t.tree) << std::endl;
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

int find_max(BSTNode *t)
{
    BSTNode* p =t;
    while (p->lchild)
        p = p->lchild;
    return p->data;
}

int find_min(BSTNode *t)
{
    BSTNode* p =t;
    while (p->rchild)
        p = p->rchild;
    return p->data;
}