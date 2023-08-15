/*
 * 二叉树链式存储
 */

#include <iostream>

using namespace std;
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
// todo
bool search (Tree &tree, int x);
// 递归
void Porder(TreeNode* r); // 先序
void inorder(TreeNode* r); // 中序
void epilogue(TreeNode* r); // 后序
void sequence(TreeNode* r); // 层序
//todo 非递归
void Porder1(TreeNode* r);
void inorder1(TreeNode* r);
void epilogue1(TreeNode* r);

int main()
{
    Tree tree;
    puts("请输入根节点");
    tree.root = CreateTree();
    cout << "先序：" ;
    Porder(tree.root);
    puts("");
    cout << "中序：";
    inorder(tree.root);
    puts("");
    cout << "后序：";
    epilogue(tree.root);
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

bool search (Tree &tree, int x)
{
    return true;
}

void Porder(TreeNode* r)
{
    if (!r)
        return ;
    cout << r->element << " ";
    Porder(r->leftson);
    Porder(r->rightson);
}

void inorder(TreeNode* r)
{
    if (!r)
        return ;
    inorder(r->leftson);
    cout << r->element << " ";
    inorder(r->rightson);
}

void epilogue(TreeNode* r)
{
    if (!r)
        return ;
    epilogue(r->leftson);
    epilogue(r->rightson);
    cout << r->element << " ";
}

void sequence(TreeNode* r)
{

}

void Porder1(TreeNode* r)
{

}

void inorder1(TreeNode* r)
{

}

void epilogue1(TreeNode* r)
{

}
