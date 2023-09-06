#include <iostream>
typedef int ElemType;
struct avlNode
{
    ElemType data;
    int bf; // 平衡因子
    avlNode *lchild, *rchild;
};

struct AVL_Tree
{
    avlNode *root;
};
void L_rotate(avlNode *&t);
void R_rotate(avlNode *&t);
void LeftBalance(avlNode *&t);
void RightBalance(avlNode *&t);
bool InsertAVL(avlNode *&t,int e, bool *flag);

int main()
{

    return 0;
}

void L_rotate(avlNode *&t)
{

}

void R_rotate(avlNode *&t)
{

}

void LeftBalance(avlNode *&t)
{

}

void RightBalance(avlNode *&t)
{

}

bool InsertAVL(avlNode *&t,int e, bool *flag)
{

}