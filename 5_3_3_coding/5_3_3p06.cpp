/*
 * p06
 */

#include <iostream>

using namespace std;
const int MaxSize = 110;
typedef int ElemType;
struct TreeNode
{
    ElemType element;
    TreeNode *leftson, *rightson;
};
struct Tree
{
    TreeNode *root;
};

void Init(Tree &tree);
TreeNode* CreateTree(int pl, int pr, int il, int ir);
int porder[] = {2, 1, 6, 7, 5, 3};
int iorder[] = {1, 6, 2, 3, 5, 7};
void epilogue(TreeNode* r);

int main()
{
    Tree tree;
    Init(tree);
    tree.root = CreateTree(0, sizeof porder / 4 - 1, 0, sizeof iorder / 4 - 1);
    cout << "ºóÐò±éÀúÎª£º";
    epilogue(tree.root);
    return 0;
}

void Init(Tree &tree)
{
    tree.root = nullptr;
}

TreeNode* CreateTree(int pl, int pr, int il, int ir)
{
    if (pl > pr)
        return nullptr;
    Tree tree;
    Init(tree);
    tree.root = new TreeNode;
    tree.root->element = porder[pl];
    int k;
    for (int i = il; i <= ir; ++ i)
        if (iorder[i] == porder[pl])
        {
            k = i;
            break;
        }
    int numLtree = k - il;
    tree.root->leftson = CreateTree(pl + 1, pl + numLtree, il, k - 1);
    tree.root->rightson = CreateTree(pl + numLtree + 1, pr, k + 1, ir);
    return tree.root;
}

void epilogue(TreeNode* r)
{
    if (!r)
        return ;
    epilogue(r->leftson);
    epilogue(r->rightson);
    cout << r->element << " ";
}