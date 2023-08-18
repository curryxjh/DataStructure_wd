/*
 * p07
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
bool IsCompleteTree(Tree &tree);
bool IsCompleteTree_v2(Tree &tree);
int main()
{
    Tree tree;
    puts("请输入根节点");
    tree.root = CreateTree();
    cout << "判断方法1：";
    if (IsCompleteTree(tree))
        puts("是");
    else
        puts("不是");
    cout << "判断方法2：";
    if (IsCompleteTree_v2(tree))
        puts("是");
    else
        puts("不是");
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

bool IsCompleteTree(Tree &tree)
{
    if (! tree.root)
        return true;
    Queue q;
    bool leaf = false;
    InitQueue(q);
    EnQueue(q, tree.root);
    TreeNode *p;
    while (! IsEmpty(q))
    {
        DeQueue(q, p);
        if (leaf && (p->leftson || p->rightson) || (! p->leftson && p->rightson))
            return false;
        if (p->leftson)
            EnQueue(q, p->leftson);
        if (p->rightson)
            EnQueue(q, p->rightson);
        if ((p->leftson && ! p->rightson) || (! p->leftson && ! p->rightson))
            leaf = true;
    }
    return true;
}

bool IsCompleteTree_v2(Tree &tree)
{
    if (! tree.root)
        return true;
    Queue q;
    InitQueue(q);
    EnQueue(q, tree.root);
    TreeNode *p;
    int idx = 0;
    while (! IsEmpty(q))
    {
        DeQueue(q, p);
        if (p->element != -1)
        {
            if (p->leftson)
                EnQueue(q, p->leftson);
            else
            {
                TreeNode *tmp = new TreeNode{-1, NULL, NULL};
                EnQueue(q,tmp);
            }
            if(p->rightson)
                EnQueue(q, p->rightson);
            else
            {
                TreeNode *tmp = new TreeNode{-1, NULL, NULL};
                EnQueue(q,tmp);
            }
        }
        else
        {
            while (!IsEmpty(q))
            {
                DeQueue(q, p);
                if (p->element != -1)
                    return false;
            }
            return true;
        }
    }
    return true;
}
