#include <iostream>
#include <algorithm>
typedef int ElemType;
struct BSTNode
{
    ElemType data;
    BSTNode *lchild, *rchild;
    int count;
};

struct BST_Tree
{
    BSTNode *tree;
};

int a[12] = {17,12,19,10,15,18,25,8,11,13,16,22};
int alen = 12;
bool BST_Insert(BSTNode *&t, ElemType k);
void Create_BST(BST_Tree &t, ElemType a[], int n);
BSTNode* find_k(BSTNode *t, ElemType k);

int main()
{
    BST_Tree t;
    Create_BST(t, a, alen);
    BSTNode *p = find_k(t.tree, 5);
    std::cout << p->data << std::endl;
    std::sort(a, a + 12);
    for (int i = 0; i < 12; ++ i)
        std::cout << a[i] << " ";
    return 0;
}

bool BST_Insert(BSTNode *&t, ElemType k)
{
    if (!t)
    {
        t = new BSTNode;
        t->data = k;
        t->lchild = t->rchild = NULL;
        t->count = 1;
        return true;
    }
    else if (k == t->data)
        return false;
    else if (k < t->data)
    {
        bool flag =  BST_Insert(t->lchild, k);
        if (flag)
            ++ t->count;
        return flag;
    }
    else
    {
        bool flag = BST_Insert(t->rchild, k);
        if (flag)
            ++ t->count;
        return flag;
    }
}

void Create_BST(BST_Tree &t, ElemType a[], int n)
{
    t.tree = NULL;
    for (int i = 0; i < n; ++ i)
        BST_Insert(t.tree, a[i]);
}

BSTNode* find_k(BSTNode *t, ElemType k)
{
    if (k < 1 || k > t->count)
        return NULL;
    if (! t->lchild)
    {
        if (k == 1)
            return t;
        else
            return find_k(t->rchild, k - 1);
    }
    else
    {
        if (t->lchild->count == k - 1)
            return t;
        if (t->lchild->count > k - 1)
            return find_k(t->lchild, k);
        if (t->lchild->count < k - 1)
            return find_k(t->rchild, k - (t->lchild->count + 1));
    }
}