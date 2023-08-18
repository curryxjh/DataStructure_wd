/*
 * p11
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
void Porder(TreeNode* r);
void Del_x(TreeNode *&r, int x);


int main()
{
    Tree tree;
    puts("��������ڵ�");
    tree.root = CreateTree();
    cout <<"��ɾ����ֵ��";
    int x;
    cin >> x;
    Porder(tree.root);
    puts("");
    Del_x(tree.root, x);
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
        cout << "������������" << endl;
        root->leftson = CreateTree();
        cout << "������������" << endl;
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

void Del_x(TreeNode *&r, int x)
{
    if (!r)
        return ;
    if (r->element == x)
    {
        r = NULL;
        return ;
    }
    Del_x(r->leftson, x);
    Del_x(r->rightson, x);
}