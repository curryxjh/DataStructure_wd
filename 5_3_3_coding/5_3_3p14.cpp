/*
 * p14
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
int sequence(TreeNode* r);

int main()
{
    Tree tree;
    puts("请输入根节点");
    tree.root = CreateTree();
    tree.root->deep = 1;
    int maxwidth = sequence(tree.root);
    cout << maxwidth << endl;
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

int sequence(TreeNode* r)
{
    TreeNode* Queue[110];
    int front = -1, rear = -1;
    Queue[++ rear] = r;
    while (front < rear)
    {
        TreeNode *p = Queue[++ front];
        ++ level[p->deep];
        if (p->leftson)
        {
            p->leftson->deep = p->deep + 1;
            Queue[++ rear] = p->leftson;
        }
        if (p->rightson)
        {
            p->rightson->deep = p->deep + 1;
            Queue[++ rear] = p->rightson;
        }
    }
    int maxWidth = 0;
    for (int i = 0; i < 110; ++ i)
        if (level[i] > maxWidth)
            maxWidth = level[i];
    return maxWidth;
}