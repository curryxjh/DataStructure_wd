/*
 * p16
 */

#include <iostream>

using namespace std;
const int MaxSize = 110;
typedef int ElemType;
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
int level[110];
void Init(Tree &tree);
TreeNode* CreateTree();
void leaf(TreeNode *& r);
TreeNode *pre, *head;

int main()
{
    Tree tree;
    puts("请输入根节点");
    tree.root = CreateTree();
    leaf(tree.root);
    while (head)
    {
        cout << head->element << " ";
        head = head->rightson;
    }
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
void leaf(TreeNode *& r)
{
    if (r)
    {
        leaf (r->leftson);
        if (! r->leftson && ! r->rightson)
        {
            if (!pre)
            {
                head = r;
                pre = r;
            }
            else
            {
                pre->rightson = r;
                pre = r;
            }
        }
        leaf(r->rightson);
        pre->rightson = NULL;
    }
}