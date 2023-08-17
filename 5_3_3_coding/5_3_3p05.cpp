/*
 * p05
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
struct Queue
{
    int front, rear;
    TreeNode* data[MaxSize];
};
struct Tree
{
    TreeNode *root;
};
void InitQueue(Queue &q);
bool IsEmpty(Queue &q);
bool EnQueue(Queue &q, TreeNode *x);
bool DeQueue(Queue &q, TreeNode *&x);

void Init(Tree &tree);
TreeNode* CreateTree();
int Height(Tree &tree);

int main()
{
    Tree tree;
    puts("请输入根节点");
    tree.root = CreateTree();
    cout << "树的高度为：" << Height(tree) << endl;
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


void InitQueue(Queue &q)
{
    q.front = q.rear = -1;
}

bool IsEmpty(Queue &q)
{
    return q.front == q.rear;
}

bool EnQueue(Queue &q, TreeNode *x)
{
    if (q.rear == MaxSize)
        return false;
    q.data[++ q.rear] = x;
    return true;
}

bool DeQueue(Queue &q, TreeNode *&x)
{
    if (IsEmpty(q))
        return false;
    x = q.data[++ q.front];
    return true;
}

int Height(Tree &tree)
{
    int height = 0;
    if (! tree.root)
        return 0;
    Queue q;
    InitQueue(q);
    int last = 0;
    EnQueue(q, tree.root);
    TreeNode *p;
    while (!IsEmpty(q))
    {
        DeQueue(q, p);
        if (p->leftson)
            EnQueue(q, p->leftson);
        if (p->rightson)
            EnQueue(q, p->rightson);
        if (q.front == last)
        {
            ++height;
            last = q.rear;
        }
    }
    return height;
}