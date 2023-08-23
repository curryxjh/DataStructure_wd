/*
 * p17
 */

#include <iostream>

using namespace std;
typedef char ElemType;
struct TreeNode
{
    ElemType element;
    TreeNode *leftson, *rightson;
    int deep;
};
struct Tree
{
    TreeNode *root;
};

void BuildTree(TreeNode *&r);
bool IsSimilar(TreeNode *&r1, TreeNode *&r2);

int main()
{
    Tree tree1, tree2;
    tree1.root = tree2.root = NULL;
    cout << "first tree:";
    BuildTree(tree1.root);
    cout << "second tree:";
    BuildTree(tree2.root);
    if (IsSimilar(tree1.root, tree2.root))
        puts("YES");
    else
        puts("No");
    return 0;
}

void BuildTree(TreeNode *&r)
{
    char ch;
    cin >> ch;
    if (ch == '#')
    {
        r = NULL;
        return;
    }
    else
    {
        r = new TreeNode;
        r->element = ch;
        r->leftson = NULL;
        r->rightson = NULL;
        BuildTree(r->leftson);
        BuildTree(r->rightson);
    }
}

bool IsSimilar(TreeNode *&r1, TreeNode *&r2)
{
    bool left, right;
    if (!r1 && ! r2)
        return true;
    else if (! r1 || ! r2)
        return false;
    else
    {
        left = IsSimilar(r1->leftson, r2->leftson);
        right = IsSimilar(r1->rightson, r2->rightson);
        return left && right;
    }
}