/*
 * p06
 */
#include <iostream>
typedef char ElemType;
const int MaxSize = 110;
struct CSNode
{
    ElemType data;
    CSNode *firstchild, *nextsibling;
};

struct CSTree
{
    CSNode *root;
};
void createCSTree(CSNode *& r, ElemType e[], int degree[], int n);
void disp(CSNode *r);
ElemType e[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
int degree[] = {3, 2, 1, 0, 0, 0, 0};

int main()
{
    CSTree tree;
    createCSTree(tree.root, e, degree, 7);
    disp(tree.root);
    return 0;
}

void createCSTree(CSNode *& r, ElemType e[], int degree[], int n)
{
    CSNode **pointer = new CSNode*[MaxSize];
    for (int i = 0; i < n; ++ i)
    {
        pointer[i] = new CSNode;
        pointer[i]->data = e[i];
        pointer[i]->firstchild = pointer[i]->nextsibling = NULL;
    }
    int k = 0;

    for (int i = 0; i < n; ++ i)
    {
        int d = degree[i];
        if (d)
        {
            ++ k;
            pointer[i]->firstchild = pointer[k];
            for (int j = 2; j <= d; ++ j)
            {
                ++ k;
                pointer[k-1]->nextsibling = pointer[k];
            }
        }
    }
    r = pointer[0];

    delete []pointer;
}

void disp(CSNode *r)
{
    if (! r)
        return ;
    std::cout << r->data << " ";
    disp(r->firstchild);
    disp(r->nextsibling);
}