/*
 * p13
 */

#include <iostream>

using namespace std;
const int MaxSize = 110;
typedef char ElemType;
struct TreeNode
{
    ElemType element;
    TreeNode *leftson, *rightson;
};
struct Tree
{
    TreeNode *root;
    bool tag;
};
void Init(Tree &tree);
void BuildTree(TreeNode *&r);
TreeNode* Ancestor(TreeNode *&r, TreeNode *&p, TreeNode *&q);

int main()
{
    Tree tree;
    Init(tree);
    BuildTree(tree.root);
    TreeNode *p = tree.root -> leftson ->rightson;
    TreeNode *q = tree.root -> rightson -> leftson;
    TreeNode *lca = Ancestor(tree.root, p, q);
    cout << lca->element << endl;
    return 0;
}

void Init(Tree &tree)
{
    tree.root = nullptr;
}

void BuildTree(TreeNode *&r)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        r = NULL;
    else
    {
        r = new TreeNode;
        r->element = ch;
        r->leftson = NULL  ;
        r->rightson = NULL;
        BuildTree(r->leftson);
        BuildTree(r->rightson);
    }
}
// ABD##E##CF##G##
TreeNode* Ancestor(TreeNode *&r, TreeNode *&p, TreeNode *&q)
{
    Tree s1[110], s2[110];
    int top1 = 0, top2 = 0;
    TreeNode *bt = r;
    while (bt || top1 > 0)
    {
        while (bt)
        {
            s1[++ top1].root = bt;
            s1[top1].tag = 0;
            bt = bt->leftson;
        }
        while (top1 > 0 && s1[top1].tag == 1)
        {
            if (s1[top1].root == p)
            {
                for (int i = 1; i <= top1; ++ i)
                {
                    s2[i] = s1[i];
                    top2 = top1;
                }
            }
            if (s1[top1].root == q)
            {
                for (int i = top1; i > 0; -- i)
                    for (int j = top2; j > 0; -- j)
                        if (s1[i].root == s2[j].root)
                            return s1[i].root;
            }
             -- top1;
        }
        if (top1 != 0)
        {
            s1[top1].tag = 1;
            bt = s1[top1].root->rightson;
        }
    }
    return NULL;
}
