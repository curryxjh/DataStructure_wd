/*
 * p08
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
int cntNodeTwice(Tree &tree);

int main()
{
    Tree tree;
    puts("请输入根节点");
    tree.root = CreateTree();
    cout << "双分支节点个数为：" << cntNodeTwice(tree) << endl;
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

int cntNodeTwice(Tree &tree)
{
    Queue q;
    InitQueue(q);
    int cnt = 0;
    TreeNode *p;
    EnQueue(q, tree.root);
    while (!IsEmpty(q))
    {
        DeQueue(q, p);
        if (p->leftson && p->rightson)
            ++ cnt;
        if (p->leftson)
            EnQueue(q, p->leftson);
        if (p->rightson)
            EnQueue(q, p->rightson);
    }
    return cnt;
}