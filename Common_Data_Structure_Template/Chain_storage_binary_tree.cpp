/*
 * ��������ʽ�洢
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
// �ݹ�
void Porder(TreeNode* r); // ����
void inorder(TreeNode* r); // ����
void epilogue(TreeNode* r); // ����
void sequence(TreeNode* r); // ����
//todo �ǵݹ�
void Porder1(TreeNode* r);
void inorder1(TreeNode* r);
void epilogue1(TreeNode* r);

int main()
{
    Tree tree;
    puts("��������ڵ�");
    tree.root = CreateTree();
    cout << "����" ;
    Porder(tree.root);
    puts("");
    cout << "����";
    inorder(tree.root);
    puts("");
    cout << "����";
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
        cout << "������������" << endl;
        root->leftson = CreateTree();
        cout << "������������" << endl;
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
