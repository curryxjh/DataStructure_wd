/*
 * p10
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
TreeNode* CreateTree();
int Find_k(TreeNode *&r);
void Porder(TreeNode* r);
int k, id = 1;

int main()
{
    Tree tree;
    puts("请输入根节点");
    tree.root = CreateTree();
    puts("请输入需要获取先序遍历中第几个节点的值");
    cin >> k;
    if (k == -1)
    {
        puts("树中节点不足");
        return 0;
    }
    cout << "值为：" << Find_k(tree.root) << endl;
    cout << "先序：";
    Porder(tree.root);
    return 0;
}

void Init(Tree &tree)
{
    tree.root = nullptr;
}

TreeNode* CreateTree()
{
    TreeNode *root = new TreeNode;
    int e;
    cin >> e;
    if (e == -1)
        return NULL;
    else
    {
        root->element = e;
        cout << "请输入左子树" << endl;
        root->leftson = CreateTree();
        cout << "请输入右子树" << endl;
        root->rightson = CreateTree();
        return root;
    }
}


void Porder(TreeNode* r)
{
    if (!r)
        return ;
    cout << r->element << " ";
    Porder(r->leftson);
    Porder(r->rightson);
}
int Find_k(TreeNode *&r)
{
    if (!r)
        return -1;
    if (id == k)
        return r->element;
    ++ id;
    int val = Find_k(r->leftson);
    if (val != -1)
        return val;
    val = Find_k(r->rightson);
    return val;
}
